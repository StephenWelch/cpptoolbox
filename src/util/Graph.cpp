//
// Created by stephen on 9/5/19.
//

#include "Graph.h"

void Graph::add_yvalue(const std::string &name, const double &value) {
    // If key doesn't exist
    if(yvalues.find(name) == yvalues.end()) {
        std::vector<double> data;
        yvalues.insert(std::pair<std::string, std::vector<double>>(name, data));
    }
    yvalues[name].push_back(value);
}

void Graph::add_xvalue(const double &x) {
    xvalues.push_back(x);
}

void Graph::plot(const std::string &title) {
    for(const auto &entry : yvalues) {
        plt::named_plot(entry.first, xvalues, entry.second);
    }

    plt::legend();
    plt::title(title);
    plt::show();
}
