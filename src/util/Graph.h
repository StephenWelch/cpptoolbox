//
// Created by stephen on 9/5/19.
//

#ifndef JOURNEY_GRAPH_H
#define JOURNEY_GRAPH_H

#include <unordered_map>
#include <vector>
#include <matplotlibcpp.h>

namespace plt = matplotlibcpp;

class Graph {
private:
    Graph() = default;

    std::unordered_map<std::string, std::vector<double>> yvalues;
    std::vector<double> xvalues;
public:
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph &) = delete;
    Graph(Graph &&) = delete;
    Graph & operator=(Graph &&) = delete;

    static Graph& instance() {
        static Graph graph;
        return graph;
    }

    void add_yvalue(const std::string &name, const double &value);
    void add_xvalue(const double& x);
    void plot(const std::string &title);
};


#endif //JOURNEY_GRAPH_H
