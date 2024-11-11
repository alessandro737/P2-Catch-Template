#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "Graph.h"

using namespace std;


TEST_CASE("Example PageRank Output Test", "[flag]") {
  // the following is a "raw string" - you can write the exact input (without
  //   any indentation!) and it should work as expected
  string input = R"(7 2
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com)";

  string expectedOutput = R"(facebook.com 0.20
gmail.com 0.20
google.com 0.10
maps.com 0.30
ufl.edu 0.20
)";

  Graph graph;
  int n = graph.parseInput(input);
  string actualOutput = graph.pageRankAlgo(n);

  REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Minimal graph with a single edge", "[pagerank]") {
    string input = R"(2 10
A B
B A)";
    string expectedOutput = R"(A 0.50
B 0.50
)";

    Graph graph;
    int power_iterations = graph.parseInput(input);
    string actualOutput = graph.pageRankAlgo(power_iterations);

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Triangular cycle graph", "[pagerank]") {
    std::string input = R"(3 1
A B
B C
C A)";
    std::string expectedOutput = R"(A 0.33
B 0.33
C 0.33
)";

    Graph graph;
    int power_iterations = graph.parseInput(input);
    std::string actualOutput = graph.pageRankAlgo(power_iterations);

    REQUIRE(actualOutput == expectedOutput);
}

// The following test cases are generated by:
// PageRank Tester
// Developed by: R Chase Mooney

TEST_CASE("Random Generated Test Case 1", "[pageranktester]") {
    std::string input = R"(113 7
python.org reactjs.org
openai.com pcbuildinguf.com
youtube.com apple.com
twitter.com weather.com
openai.com ufl.edu
openai.com microsoft.com
google.com microsoft.com
zoom.us aman.com
pcbuildinguf.com samsung.com
twitter.com roblox.com
openai.com zoom.us
weather.com twitter.com
google.com pcbuildinguf.com
youtube.com pcbuildinguf.com
apple.com aman.com
ufl.edu disney.com
chase.com mozilla.org
aman.com roblox.com
microsoft.com weather.com
microsoft.com zoom.us
chase.com google.com
reactjs.org microsoft.com
pcbuildinguf.com facebook.com
weather.com pcbuildinguf.com
google.com github.com
apple.com zoom.us
pcbuildinguf.com weather.com
instagram.com openai.com
samsung.com openai.com
microsoft.com reactjs.org
google.com reactjs.org
disney.com ufl.edu
instagram.com facebook.com
google.com roblox.com
weather.com roblox.com
mozilla.org disney.com
stackoverflow.com openai.com
youtube.com stackoverflow.com
apple.com python.org
disney.com github.com
pcbuildinguf.com openai.com
google.com twitter.com
mozilla.org twitter.com
samsung.com reactjs.org
python.org roblox.com
facebook.com aman.com
zoom.us pcbuildinguf.com
aman.com reactjs.org
disney.com reactjs.org
reactjs.org ufl.edu
twitter.com reactjs.org
openai.com youtube.com
disney.com google.com
roblox.com disney.com
roblox.com python.org
zoom.us microsoft.com
openai.com github.com
pcbuildinguf.com chase.com
google.com mozilla.org
samsung.com aman.com
chase.com twitter.com
weather.com microsoft.com
google.com ufl.edu
chase.com instagram.com
facebook.com twitter.com
weather.com samsung.com
ufl.edu roblox.com
github.com ufl.edu
aman.com facebook.com
reactjs.org twitter.com
twitter.com zoom.us
zoom.us youtube.com
chase.com roblox.com
mozilla.org chase.com
chase.com aman.com
twitter.com google.com
chase.com microsoft.com
github.com instagram.com
facebook.com chase.com
instagram.com pcbuildinguf.com
weather.com disney.com
google.com zoom.us
instagram.com ufl.edu
roblox.com zoom.us
disney.com instagram.com
pcbuildinguf.com aman.com
github.com pcbuildinguf.com
roblox.com weather.com
chase.com python.org
weather.com instagram.com
facebook.com openai.com
apple.com facebook.com
ufl.edu stackoverflow.com
instagram.com roblox.com
github.com python.org
github.com weather.com
samsung.com weather.com
apple.com disney.com
chase.com github.com
disney.com facebook.com
facebook.com samsung.com
weather.com aman.com
instagram.com weather.com
zoom.us apple.com
samsung.com disney.com
python.org weather.com
google.com instagram.com
microsoft.com python.org
facebook.com google.com
disney.com mozilla.org
weather.com mozilla.org
facebook.com microsoft.com
zoom.us twitter.com
)";
    std::string expectedOutput = R"(aman.com 0.04
apple.com 0.02
chase.com 0.02
disney.com 0.06
facebook.com 0.04
github.com 0.02
google.com 0.03
instagram.com 0.03
microsoft.com 0.07
mozilla.org 0.02
openai.com 0.05
pcbuildinguf.com 0.05
python.org 0.05
reactjs.org 0.08
roblox.com 0.08
samsung.com 0.02
stackoverflow.com 0.02
twitter.com 0.07
ufl.edu 0.06
weather.com 0.09
youtube.com 0.02
zoom.us 0.06
)";

    Graph graph;
    int power_iterations = graph.parseInput(input);
    std::string actualOutput = graph.pageRankAlgo(power_iterations);

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Random Generated Test Case 2", "[pageranktester]") {
    std::string input = R"(33 1
google.com github.com
google.com aman.com
samsung.com weather.com
aman.com samsung.com
samsung.com aman.com
ufl.edu github.com
instagram.com aman.com
pcbuildinguf.com google.com
github.com microsoft.com
weather.com pcbuildinguf.com
disney.com microsoft.com
pcbuildinguf.com weather.com
weather.com disney.com
google.com instagram.com
openai.com github.com
pcbuildinguf.com instagram.com
openai.com ufl.edu
samsung.com ufl.edu
disney.com instagram.com
google.com ufl.edu
ufl.edu openai.com
disney.com github.com
github.com disney.com
aman.com github.com
instagram.com samsung.com
disney.com weather.com
github.com aman.com
weather.com instagram.com
aman.com ufl.edu
ufl.edu weather.com
ufl.edu disney.com
instagram.com github.com
pcbuildinguf.com openai.com
)";
    std::string expectedOutput = R"(aman.com 0.09
disney.com 0.09
github.com 0.09
google.com 0.09
instagram.com 0.09
microsoft.com 0.09
openai.com 0.09
pcbuildinguf.com 0.09
samsung.com 0.09
ufl.edu 0.09
weather.com 0.09
)";

    Graph graph;
    int power_iterations = graph.parseInput(input);
    std::string actualOutput = graph.pageRankAlgo(power_iterations);

    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Random Generated Test Case 3", "[pageranktester]") {
    std::string input = R"(46 6
stackoverflow.com instagram.com
disney.com youtube.com
getbootstrap.com openai.com
getbootstrap.com disney.com
stackoverflow.com getbootstrap.com
disney.com weather.com
samsung.com stackoverflow.com
github.com pcbuildinguf.com
zoom.us github.com
python.org zoom.us
github.com instagram.com
apple.com zoom.us
python.org instagram.com
zoom.us samsung.com
samsung.com openai.com
python.org github.com
weather.com stackoverflow.com
github.com openai.com
instagram.com python.org
pcbuildinguf.com github.com
zoom.us stackoverflow.com
zoom.us python.org
youtube.com python.org
stackoverflow.com pcbuildinguf.com
reactjs.org samsung.com
youtube.com github.com
samsung.com getbootstrap.com
github.com getbootstrap.com
reactjs.org instagram.com
github.com apple.com
pcbuildinguf.com disney.com
getbootstrap.com youtube.com
openai.com getbootstrap.com
youtube.com zoom.us
getbootstrap.com zoom.us
weather.com reactjs.org
stackoverflow.com openai.com
zoom.us reactjs.org
apple.com openai.com
python.org openai.com
pcbuildinguf.com weather.com
getbootstrap.com reactjs.org
python.org stackoverflow.com
instagram.com zoom.us
python.org youtube.com
github.com zoom.us
)";
    std::string expectedOutput = R"(apple.com 0.01
disney.com 0.04
getbootstrap.com 0.15
github.com 0.07
instagram.com 0.08
openai.com 0.10
pcbuildinguf.com 0.03
python.org 0.09
reactjs.org 0.07
samsung.com 0.06
stackoverflow.com 0.08
weather.com 0.03
youtube.com 0.07
zoom.us 0.12
)";

    Graph graph;
    int power_iterations = graph.parseInput(input);
    std::string actualOutput = graph.pageRankAlgo(power_iterations);

    REQUIRE(actualOutput == expectedOutput);
}