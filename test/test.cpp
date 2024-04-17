/*#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>

#include "AdjacencyList.h"

using namespace std;


// you must write 5 unique, meaningful tests for extra credit on this project!

TEST_CASE("test case 1", "[flag]") {
    AdjacencyList graph;
    string input = R"(7 2
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

    //Populate the graph with edges from the input string
    auto config_vars = graph.addEdgesFromString(input);
    int power_iterations = config_vars.second;
    string actualOutput = graph.PageRank(power_iterations);

    string expectedOutput = R"(facebook.com 0.20
gmail.com 0.20
google.com 0.10
maps.com 0.30
ufl.edu 0.20
)";

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("test case 2: Edges are added correctly", "[AdjacencyList][addEdge]") {
    AdjacencyList graph;
    graph.addEdge("google.com", "facebook.com");
    graph.addEdge("google.com", "gmail.com");

    REQUIRE(graph.getAdjacencyListSize("google.com") == 2);
    REQUIRE(graph.getAdjacencyListSize("facebook.com") == 0);
}



TEST_CASE("test case 3:PageRank computation is correct", "[PageRank]") {
    AdjacencyList graph;
    //Add edges
    graph.addEdge("PageA", "PageB");
    graph.addEdge("PageB", "PageA");

    //Call PageRank
    string result = graph.PageRank(1);

    REQUIRE(!result.empty());
}

TEST_CASE("test case 4: seeing if anything breaks", "[flag]") {
    AdjacencyList graph;
    string input = R"(7 49
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

    //Populate the graph with edges from the input string
    auto config_vars = graph.addEdgesFromString(input);
    int power_iterations = config_vars.second;

    string actualOutput = graph.PageRank(power_iterations);

    string expectedOutput = R"(facebook.com 0.24
gmail.com 0.18
google.com 0.12
maps.com 0.24
ufl.edu 0.23
)";

    REQUIRE(actualOutput == expectedOutput);
}


TEST_CASE("test case 5: large number of edges, E = V^2", "[flag]") {
    AdjacencyList graph;
    string input = R"(25 2
A B
A C
A D
A E
B A
B C
B D
B E
C A
C B
C D
C E
D A
D B
D C
D E
E A
E B
E C
E D
A B
B C
C D
D E
E A)";

    //Populate the graph with edges from the input string
    auto config_vars = graph.addEdgesFromString(input);
    int power_iterations = config_vars.second;

    string actualOutput = graph.PageRank(power_iterations);

    string expectedOutput = R"(A 0.20
B 0.20
C 0.20
D 0.20
E 0.20
)";




    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("this test case is a mimic chest don't run it", "[flag]") {
    AdjacencyList graph;
    string input = R"(25 9999
A B
A C
A D
A E
B A
B C
B D
B E
C A
C B
C D
C E
D A
D B
D C
D E
E A
E B
E C
E D
A B
B C
C D
D E
E A)";

    //Populate the graph with edges from the input string
    auto config_vars = graph.addEdgesFromString(input);
    int power_iterations = config_vars.second;

    string actualOutput = graph.PageRank(power_iterations);

    string expectedOutput = R"(A 0.20
B 0.20
C 0.20
D 0.20
E 0.20
)";




    REQUIRE(actualOutput == expectedOutput);
}
*/