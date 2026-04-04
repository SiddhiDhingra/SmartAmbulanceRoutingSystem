#include "../include/graph.h"
#include "../include/dijkstra.h"
#include "../include/assignment.h"

int main() {

    cout << "========================================" << endl;
    cout << "   Smart Ambulance Routing System" << endl;
    cout << "========================================" << endl;

    // --- City Map Input ---
    cout << "\nEnter number of locations in city: ";
    cin >> V;

    int edges;
    cout << "Enter number of roads: ";
    cin >> edges;

    cout << "Enter each road (location1 location2 traveltime):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    // --- Ambulance Input ---
    int numAmb;
    cout << "\nEnter number of ambulances: ";
    cin >> numAmb;

    vector<Ambulance> ambulances;
    for (int i = 0; i < numAmb; i++) {
        int loc;
        cout << "Enter location of Ambulance " << i+1 << ": ";
        cin >> loc;
        ambulances.push_back({i+1, loc, true});
    }

    // --- Accident Input ---
    int numAcc;
    cout << "\nEnter number of accidents: ";
    cin >> numAcc;

    vector<Accident> accidents;
    for (int i = 0; i < numAcc; i++) {
        int loc, pri;
        cout << "Enter location of Accident " << i+1 << ": ";
        cin >> loc;
        cout << "Enter priority (1=Critical, 2=High, 3=Normal): ";
        cin >> pri;
        accidents.push_back({i+1, loc, pri});
    }

    // --- Processing ---
    cout << "\nCalculating shortest paths..." << endl;
    vector<vector<int>> cost = buildCostMatrix(ambulances, accidents);

    printCostMatrix(cost, ambulances, accidents);
    assignAmbulances(ambulances, accidents, cost);

    return 0;
}
