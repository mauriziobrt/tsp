/// @file
///	@ingroup 	minexamples
///	@copyright	Copyright 2018 The Min-DevKit Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#include "c74_min.h"
#include<iostream>
#include "math.h"
#include <cstdint>
#include <sstream>
#include <vector>

#include "ortools/constraint_solver/routing.h"
#include "ortools/constraint_solver/routing_enums.pb.h"
#include "ortools/constraint_solver/routing_index_manager.h"
#include "ortools/constraint_solver/routing_parameters.h"

using namespace c74::min;

class dynamictsp : public object<dynamictsp> {
public:
    MIN_DESCRIPTION	{"Calculate travelling salesman problem using dynamic programming."};
    MIN_TAGS		{"graph theory"};
    MIN_AUTHOR		{"Maurizio Berta"};
    MIN_RELATED		{"fluid.dataset, buffer~, dict"};

    inlet<>  input	{ this, "(bang) post greeting to the max console" };
    outlet<> output	{ this, "(anything) output the message which is posted to the max console" };
    
    
    buffer_reference m_buffer { this,
        MIN_FUNCTION {    // will receive a symbol arg indicating 'binding', 'unbinding', or 'modified'
            //m_outlet_changed.send(args);
            return {};
        }
    };
    
    argument<symbol> m_in_buffer {this, "inBuffer", "Initial buffer~ from which to read.",
        MIN_ARGUMENT_FUNCTION {
            m_buffer.set(arg);
        }
    };

    struct DataModel {
        std::vector<std::vector<int>> locations;
        const int num_vehicles = 1;
        const operations_research::RoutingIndexManager::NodeIndex depot{0};
    };
    
    // @brief Generate distance matrix.
    std::vector<std::vector<int>> ComputeEuclideanDistanceMatrix(const std::vector<std::vector<int>>& locations) {
        // deve essere generata per ogni coppia di valori, invece mi sa che qua la calcola in un'altra direzione. Perchè in pratica lui fa la distanza tra un nodo e l'altro... cioè le coppie di dati dovrebbero essere tipo {chan1,chan2} per ogni i, invece io ho {chan1,...} e {chan2, ....}
        std::vector<std::vector<int>> distances = std::vector<std::vector<int>>(locations.size(), std::vector<int>(locations.size(), int{0}));
        
        for (int fromNode = 0; fromNode < locations.size(); fromNode++) {
            for (int toNode = 0; toNode < locations.size(); toNode++) {
                if (fromNode != toNode)
                    distances[fromNode][toNode] = static_cast<int>(std::hypot((locations[toNode][0] - locations[fromNode][0]), (locations[toNode][1] - locations[fromNode][1])));
            }
        }
      return distances;
    }
    
    
    struct buffer_lookup
    {
        int num_chans;
        float data;
    };
    
    void display (const vector<vector<int> >& vy)
    {  for (int i = 0; i < vy.size(); i++)       // loops through each row of vy
       {  for (int j = 0; j < vy[i].size(); j++) // loops through each element of each row
              cout << " " << vy[i][j];           // prints the jth element of the ith row
          cout << endl;
       }
    }
    
    //Aggiungere una funzione seria di scaling, oppure richiedere valori normalizzati.
    float scale_map (float data_to_scale)
    {
        data_to_scale = ((data_to_scale + 1.)/2.) * 100.;
        return data_to_scale;
    }
        
    
    //! @brief Print the solution.
    //! @param[in] manager Index manager used.
    //! @param[in] routing Routing solver used.
    //! @param[in] solution Solution found by the solver.
    void PrintSolution(const operations_research::RoutingIndexManager& manager,
                       const operations_research::RoutingModel& routing, const operations_research::Assignment& solution) {
        // Inspect solution.
        LOG(INFO) << "Objective: " << solution.ObjectiveValue() << " miles";
        int64_t index = routing.Start(0);
        LOG(INFO) << "Route:";
        int64_t distance{0};
        std::stringstream route;
        while (routing.IsEnd(index) == false) {
            route << manager.IndexToNode(index).value() << " -> ";
            int64_t previous_index = index;
            index = solution.Value(routing.NextVar(index));
            distance += routing.GetArcCostForVehicle(previous_index, index, int64_t{0});
        }
        LOG(INFO) << route.str() << manager.IndexToNode(index).value();
        cout << route.str() << manager.IndexToNode(index).value() << endl;
        output.send(route.str());
        LOG(INFO) << "Route distance: " << distance << "miles";
        LOG(INFO) << "";
        LOG(INFO) << "Advanced usage:";
        LOG(INFO) << "Problem solved in " << routing.solver()->wall_time() << "ms";
    }

    void Tsp() {
        buffer_lock<> b(m_buffer);
        vector<vector<int>> v2;
        if(b.valid()) {
            vector<int> v;
            for(int i = 0; i < b.frame_count(); i++)
            {
                vector<int> v1;
                v1.push_back((int) scale_map(b.lookup(i,0)));
                v1.push_back((int) scale_map(b.lookup(i,1)));
                v2.push_back(v1);
            }
        
        
        // Instantiate the data problem.
        DataModel data;
        
        data.locations = v2;
                // Create Routing Index Manager
        display(data.locations);
//
        operations_research::RoutingIndexManager manager(data.locations.size(), data.num_vehicles,
                                    data.depot);
//
//        // Create Routing Model.
        operations_research::RoutingModel routing(manager);
//
        const auto distance_matrix = ComputeEuclideanDistanceMatrix(data.locations);
        const int transit_callback_index = routing.RegisterTransitCallback(
                                                                           [&distance_matrix, &manager](int64_t from_index,
                                                                                                        int64_t to_index) -> int64_t {
                                                                                                            // Convert from routing variable Index to distance matrix NodeIndex.
                                                                                                            auto from_node = manager.IndexToNode(from_index).value();
                                                                                                            auto to_node = manager.IndexToNode(to_index).value();
                                                                                                            return distance_matrix[from_node][to_node];
                                                                                                        });

//        // Define cost of each arc.
        routing.SetArcCostEvaluatorOfAllVehicles(transit_callback_index);
//
//        // Setting first solution heuristic.
        operations_research::RoutingSearchParameters searchParameters = operations_research::DefaultRoutingSearchParameters();
        searchParameters.set_first_solution_strategy(
                                                     operations_research::FirstSolutionStrategy::PATH_CHEAPEST_ARC);

//        // Solve the problem.
        const operations_research::Assignment* solution = routing.SolveWithParameters(searchParameters);
//
//        // Print solution on console.
        PrintSolution(manager, routing, *solution);
        }
    }

    // respond to the bang message to do something
    message<> bang { this, "bang", "Calculate shortest path between all points.",
        MIN_FUNCTION {
//            buffer_lock<> b(m_buffer);
//            vector<vector<int>> v2;
//            if(b.valid()) {
//                vector<int> v;
//                for(int i = 0; i < b.frame_count(); i++)
//                {
//                    vector<int> v1;
//                    v1.push_back((int) scale_map(b.lookup(i,0)));
//                    v1.push_back((int) scale_map(b.lookup(i,1)));
//                    v2.push_back(v1);
//                }
//            }
            //display(v2);
            //display(ComputeEuclideanDistanceMatrix(v2));
//            DataModel miao;
//            miao.locations = v2;
//            display(miao.locations);
            Tsp();
            //operations_research::Tsp();
            //output.send(getBufferData());       // send out our outlet
            return {};
        }
    };


    // post to max window == but only when the class is loaded the first time
    message<> maxclass_setup { this, "maxclass_setup",
        MIN_FUNCTION {
            //cout << "hello world" << endl;
            return {};
        }
    };
    
    //const std::vector<std::vector<int>> buffer_data;
    vector<vector<int>> v2;


    };


MIN_EXTERNAL(dynamictsp);
