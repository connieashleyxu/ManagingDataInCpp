// main.cpp
// Travel
// ITP365
// Connie Xu

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

// Function: structure for Airport
// Purpose: group related Airport variables
struct Airport
{
    string code;
    double latitude;
    double longitude;
};

// Function: structure for Flight
// Purpose: group related Flight variables
struct Flight
{
    string fromAirport;
    string toAirport;
    double cost;
};

class Graph
{
private:
    map<string, Airport> airports;
    vector<Flight> flights;

public:
    // Function: add airport
    // Purpose: add an airport to the graph
    // Input: airport code, latitude, longitude
    // Returns: none
    void addAirport(const string &code, double latitude, double longitude)
    {
        airports[code] = {code, latitude, longitude};
    }

    // Function: add flight
    // Purpose: add a flight to the graph
    // Input: from location, to location, cost
    // Returns: none
    void addFlight(const string &from, const string &to, double cost)
    {
        flights.push_back({from, to, cost});
        flights.push_back({to, from, cost}); // reverse direction
    }

    // Function: list airport codes
    // Purpose: lists out all airport codes
    // Input: none
    // Returns: none
    void listAirportCodes()
    {
        cout << "Airport Codes:\n";
        for (const auto &pair : airports)
        {
            cout << pair.first << "\n";
        }
    }

    // Function: is connected
    // Purpose: check if the graph is connected and show connected components
    // Input: none
    // Returns: true/false is graph connected
    bool isConnected()
    {
        map<string, bool> visited;
        int componentCount = 0;

        for (const auto &pair : airports)
        {
            visited[pair.first] = false;
        }

        for (const auto &pair : airports)
        {
            if (!visited[pair.first])
            {
                cout << "Connected Component " << ++componentCount << ": ";
                dfs(pair.first, visited); // depth first search (dfs)
                cout << "\n";
            }
        }

        return componentCount == 1; // if there is only one connected component, the graph is connected
    }

    // Function: depth first search (dfs)
    // Purpose: dfs to traverse connected components
    // Input: airport code, if airport code was visited
    // Returns: none
    void dfs(const string &airportCode, map<string, bool> &visited)
    {
        visited[airportCode] = true;
        cout << airportCode << " ";

        for (const Flight &flight : flights)
        {
            if ((flight.fromAirport == airportCode || flight.toAirport == airportCode) && !visited[flight.toAirport])
            {
                string nextAirport = (flight.fromAirport == airportCode) ? flight.toAirport : flight.fromAirport;
                dfs(nextAirport, visited);
            }
        }
    }

    // Function: show destinations
    // Purpose: show destinations and cost for a given airport
    // Input: airport code
    // Returns: none
    void showDestinations(const string &airportCode)
    {
        cout << fixed << setprecision(2); // display cost with 2 decimal places

        cout << "Destinations from " << airportCode << ":\n";
        for (const Flight &flight : flights)
        {
            if (flight.fromAirport == airportCode)
            {
                cout << "To: " << flight.toAirport << ", Cost: " << flight.cost << "\n";
            }
        }
    }

    // Function: find cheapest flight
    // Purpose: to find the cheapest flight in the whole country
    // Input: none
    // Returns: none
    void findCheapestFlight()
    {
        if (flights.empty())
        {
            cout << "No flights available.\n";
            return;
        }

        // find the minimum cost flight
        auto minFlight = min_element(flights.begin(), flights.end(),
                                     [](const Flight &f1, const Flight &f2)
                                     {
                                         return f1.cost < f2.cost;
                                     });

        cout << fixed << setprecision(2); // display cost with 2 decimal places

        cout << "Cheapest flight is from " << minFlight->fromAirport << " to " << minFlight->toAirport
             << " with a cost of $" << minFlight->cost << "\n";
    }

    // Function: find round trip destinations
    // Purpose: to find places you can get to and back from in one flight each way
    // Input: starting airport code
    // Returns: none
    void findRoundTripDestinations(const string &startAirport)
    {
        cout << fixed << setprecision(2); // display cost with 2 decimal places

        cout << "Round trip destinations from " << startAirport << ":\n";
        for (const Flight &flight : flights)
        {
            if (flight.fromAirport == startAirport)
            {
                for (const Flight &returnFlight : flights)
                {
                    if (returnFlight.fromAirport == flight.toAirport && returnFlight.toAirport == startAirport)
                    {
                        double roundTripCost = flight.cost + returnFlight.cost;
                        cout << "To: " << flight.toAirport << ", Cost: " << roundTripCost << "\n";
                    }
                }
            }
        }
    }

    // Function: find cheapest path
    // Purpose: find cheapestway to get from A to B
    // Input: destination A (source), destination B (destination)
    // Returns: none
    void findCheapestPath(const string &source, const string &destination)
    {
        cout << fixed << setprecision(2); // display cost with 2 decimal places

        map<string, double> minCost;
        map<string, string> previous;
        priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq;

        // initialize minCost and previous
        for (const auto &pair : airports)
        {
            minCost[pair.first] = numeric_limits<double>::infinity();
            previous[pair.first] = "";
        }

        minCost[source] = 0.0;
        pq.push({0.0, source});

        // Dijkstra's algorithm
        while (!pq.empty())
        {
            string currentAirport = pq.top().second;
            double currentCost = pq.top().first;
            pq.pop();

            // check if the current cost is already updated
            if (currentCost > minCost[currentAirport])
            {
                continue;
            }

            for (const Flight &flight : flights)
            {
                if (flight.fromAirport == currentAirport)
                {
                    double newCost = minCost[currentAirport] + flight.cost;
                    if (newCost < minCost[flight.toAirport])
                    {
                        minCost[flight.toAirport] = newCost;
                        previous[flight.toAirport] = currentAirport;
                        pq.push({newCost, flight.toAirport});
                    }
                }
            }
        }

        // results
        cout << "Cheapest path from " << source << " to " << destination << ":\n";
        string current = destination;
        while (current != "")
        {
            cout << current;
            if (previous[current] != "")
            {
                cout << " <- ";
            }
            current = previous[current];
        }
        if (minCost[destination] != numeric_limits<double>::infinity())
        {
            cout << "\nTotal cost: $" << minCost[destination] << "\n";
        }
        else
        {
            cout << "\nNo path found.\n";
        }
    }
};

// Function: read data from file
// Purpose: read the data from the file to populate graph
// Input: graph and file name
// Returns: none
void readDataFromFile(Graph &graph, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string type;
    while (file >> type)
    {
        if (type == "airport")
        {
            string code;
            double latitude, longitude;
            file >> code >> latitude >> longitude;
            graph.addAirport(code, latitude, longitude);
        }
        else if (type == "flight")
        {
            string from, to;
            double cost;
            file >> from >> to >> cost;
            graph.addFlight(from, to, cost);
        }
    }

    file.close();
}

int main()
{
    Graph graph;

    // read data from file
    readDataFromFile(graph, "input/data.txt");

    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. List Airport Codes\n";
        cout << "2. Check if Graph is Connected\n";
        cout << "3. Show Destinations from an Airport\n";
        cout << "4. Find Cheapest Flight\n";
        cout << "5. Find Round Trip Destinations\n";
        cout << "6. Find Cheapest Path\n";
        cout << "0. Quit\n";
        cout << "Enter your choice (0-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            graph.listAirportCodes();
            break;
        case 2:
            if (graph.isConnected())
            {
                cout << "The graph is connected.\n";
            }
            else
            {
                cout << "The graph is not connected.\n";
            }
            break;
        case 3:
        {
            string airportCode;
            cout << "Enter the airport code: ";
            cin >> airportCode;
            graph.showDestinations(airportCode);
        }
        break;
        case 4:
            graph.findCheapestFlight();
            break;
        case 5:
        {
            string startAirport;
            cout << "Enter the starting airport code: ";
            cin >> startAirport;
            graph.findRoundTripDestinations(startAirport);
        }
        break;
        case 6:
        {
            string source, destination;
            cout << "Enter the source airport code: ";
            cin >> source;
            cout << "Enter the destination airport code: ";
            cin >> destination;
            graph.findCheapestPath(source, destination);
        }
        break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 0 and 6.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}