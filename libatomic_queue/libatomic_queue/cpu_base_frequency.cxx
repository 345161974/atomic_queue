/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */

// Copyright (c) 2019 Maxim Egorushkin. MIT License. See the full licence in file LICENSE.

#include <libatomic_queue/cpu_base_frequency.hxx>

#include <fstream>
#include <string>
#include <regex>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double atomic_queue::cpu_base_frequency() {
    std::regex re("model name\\s*:[^@]+@\\s*([0-9.]+)\\s*GHz");
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::smatch m;
    for(std::string line; getline(cpuinfo, line);) {
        regex_match(line, m, re);
        if(m.size() == 2)
            return std::stod(m[1]);
    }
    return 1e9;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
