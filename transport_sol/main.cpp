//
//#include <iostream>
//#include <map>
//#include <math.h>
//#include <vector>
//#include <iterator>
//#include <random>
//
//#include <sstream>
//#include <string>
//#include <fstream>
//
//#include <set>
//#include <tuple>
//#include <vector>
//
//using namespace std;
//
//struct NODE{
//    int node;
//    float x;
//    float y;
//    int demand;
//};
//
//struct savings{
//    int start;
//    int end;
//    int s_between;
//} ;
//
//struct route{
//    vector<int>nodes_in_route;
//    int nodesAdded;
//};
//
//struct Demand{
//    int node_num;
//    int demand;
//};
//
//struct keyVal{
//    int key;
//    int val;
//    int routeIndex;
//    int indexOfnodeInRouteInResultArray;
//};
//
//
//void calculateSavings(int* costMatrix, int* hostSavingsMatrix, int rows, int cols)
//{
//    for(int i = 0; i < rows; i++)
//    {
//        for(int j = 0; j < cols; j++)
//        {
//            float valx = costMatrix[i];
//            float valy = costMatrix[j];
//            float valxy = costMatrix[i + j * rows];
//            hostSavingsMatrix[i + j * rows] = (i != j && i > j) ? valx + valy - valxy : 0;
//        }
//    }
//}
//
//struct compare { //to use in sort set l8r on
//    bool operator()(const savings& o1, const savings& o2)
//    {
//        return o1.s_between > o2.s_between;
//    }
//};
//
//void sortSavings(savings * obs, int N)
//{
//    sort(obs, obs+N, compare());
//}
//
//void getCostMatrix(NODE* nodeInfos, int *costMatrix, int rows, int cols)
//{
//    for(int i = 0; i < rows; i++)
//    {
//        for(int j = 0; j < cols; j++)
//        {
//            NODE tempNode0 = nodeInfos[i];
//            NODE tempNode1 = nodeInfos[j];
//            costMatrix[i*cols + j] = (i == j) ? 0 : 1 + float(sqrt((float)(((tempNode0.x-tempNode1.x)*(tempNode0.x - tempNode1.x))+((tempNode0.y - tempNode1.y)*(tempNode0.y - tempNode1.y)))));
//        }
//    }
//}
//
//int main(){
////
////    clock_t begin = clock();
////
////    string file = argv[1];
////    ifstream testfile(file.c_str());
//
//    int no_of_nodes;
//    int vehicleCapacity;
//    int num_of_vehicles;
//
//
//    // std::cout << "No of nodes " << endl;
//    cin >> no_of_nodes;
//
//    cin>>num_of_vehicles; //!!!!
//    // std::cout << "Capacity of each vehicle " << endl;
//    cin >> vehicleCapacity;
//
//    // Vector of (no_of_nodes + 1) * (no_of_nodes + 1) size
//    int rows = (no_of_nodes + 1), cols = (no_of_nodes + 1);
//    const int size = rows * cols;
//
//    NODE * hostN;
//
//    int * hostCostMatrix;
//
//    int * hostSavingsMatrix;
//
//    savings * hostSavingsMatrixRecord;
//
//    hostCostMatrix = new int[size];
//
//    // Assume we are starting from (0,0)
//    hostN = new NODE[no_of_nodes + 1];
//
//    hostN[0].node = 0;
//    hostN[0].x = 0;
//    hostN[0].y = 0;
//    hostN[0].demand = 0;
//
//    for(int i=0; i < no_of_nodes; i++)
//    {
//        // std::cout <<"Node Info for node (x, y, demand)" <<endl << "Node: " << i+1 << endl;
//        hostN[i+1].node = i+1;
//        cin >> hostN[i+1].demand;
//        cin >> hostN[i+1].x;
//        cin >> hostN[i+1].y;
//
//    }
//
//    getCostMatrix(hostN, hostCostMatrix, no_of_nodes + 1, no_of_nodes + 1);
//
//    hostSavingsMatrix = new int[size];
//
//    calculateSavings(hostCostMatrix, hostSavingsMatrix, no_of_nodes + 1, no_of_nodes + 1);
//
//    int count = 0;
//
//    hostSavingsMatrixRecord = new savings[rows * cols];
//
//    for (int i = 1; i < rows-1; ++i){
//        for (int j = i + 1; j < cols; ++j) {
//            hostSavingsMatrixRecord[count].start = i;
//            hostSavingsMatrixRecord[count].end = j;
//            hostSavingsMatrixRecord[count].s_between = hostSavingsMatrix[i*cols + j];
//            count++;
//        }
//    }
//
//    sortSavings(hostSavingsMatrixRecord, count);
//
//    for(int i=0; i < count; i++){
//        // std::cout << hostSavingsMatrixRecord[i].s_between << endl;
//    }
//
//    int nodeCount = no_of_nodes + 1, maxRouteCount = no_of_nodes;
//    keyVal * hostResultDict =  new keyVal[nodeCount];
//
//    // Which root for which nodeA
//    for(int i=0; i<nodeCount; ++i){
//        hostResultDict[i].key = hostN[i].node;
//        hostResultDict[i].val = 0;
//    }
//
//    route * hostRouteList = new route[maxRouteCount];
//
//    int nodesProcessed = 0;
//    int routesAdded = 0;
//    int totalSavings = 0;
//
//    // For each savings
//    for(int i = 0; i < count; i++){
//        int start = hostSavingsMatrixRecord[i].start;
//        int end = hostSavingsMatrixRecord[i].end;
//
//        int demandStart = hostN[start].demand;
//        int demandEnd = hostN[end].demand;
//
//        if (demandStart + demandEnd <= vehicleCapacity){
//
//            // std::cout << nodesProcessed << endl;
//
//            if(hostResultDict[start].val == 0 && hostResultDict[end].val == 0){
//                hostRouteList[routesAdded].nodes_in_route[0]  = start;
//                hostRouteList[routesAdded].nodes_in_route[1]  = end;
//                hostRouteList[routesAdded].nodesAdded = 2;
//                hostResultDict[start].val = 1;
//                hostResultDict[end].val = 1;
//                hostResultDict[start].routeIndex = routesAdded;
//                hostResultDict[end].routeIndex = routesAdded;
//                hostResultDict[start].indexOfnodeInRouteInResultArray = 0;
//                hostResultDict[end].indexOfnodeInRouteInResultArray = 1;
//                nodesProcessed += 2;
//                routesAdded += 1;
//            }
//            else if(hostResultDict[start].val == 1 && hostResultDict[end].val == 0){
//                int indexOfRoute = hostResultDict[start].routeIndex;
//                int numberOfNodesInRoute = hostRouteList[indexOfRoute].nodesAdded;
//                int total_demand = 0;
//                total_demand += demandEnd;
//                for (int temp_i = 0; temp_i < numberOfNodesInRoute; temp_i++){
//                    total_demand += hostN[hostRouteList[indexOfRoute].nodes_in_route[temp_i]].demand;
//                }
//                if (total_demand <= vehicleCapacity){
//                    if (hostResultDict[start].indexOfnodeInRouteInResultArray == 0 || hostResultDict[start].indexOfnodeInRouteInResultArray == (hostRouteList[indexOfRoute].nodesAdded - 1)){
//                        hostRouteList[indexOfRoute].nodes_in_route[numberOfNodesInRoute] = end;
//                        hostRouteList[indexOfRoute].nodesAdded += 1;
//                        hostResultDict[end].val = 1;
//                        hostResultDict[end].routeIndex = indexOfRoute;
//                        hostResultDict[end].indexOfnodeInRouteInResultArray = numberOfNodesInRoute;
//                        nodesProcessed += 1;
//                    }
//                }
//            }
//            else if (hostResultDict[start].val == 0 && hostResultDict[end].val == 1){
//                int indexOfRoute = hostResultDict[end].routeIndex;
//                int numberOfNodesInRoute = hostRouteList[indexOfRoute].nodesAdded;
//                int total_demand = 0;
//                total_demand += demandStart;
//                for (int temp_i = 0; temp_i < numberOfNodesInRoute; temp_i++){
//                    total_demand += hostN[hostRouteList[indexOfRoute].nodes_in_route[temp_i]].demand;
//                }
//                if (total_demand <= vehicleCapacity){
//                    if (hostResultDict[end].indexOfnodeInRouteInResultArray == 0 || hostResultDict[end].indexOfnodeInRouteInResultArray == (hostRouteList[indexOfRoute].nodesAdded - 1)){
//                        hostRouteList[indexOfRoute].nodes_in_route[numberOfNodesInRoute] = start;
//                        hostRouteList[indexOfRoute].nodesAdded += 1;
//                        hostResultDict[start].val = 1;
//                        hostResultDict[start].routeIndex = indexOfRoute;
//                        hostResultDict[start].indexOfnodeInRouteInResultArray = numberOfNodesInRoute;
//                        nodesProcessed += 1;
//                    }
//                }
//            }
//            // std::cout << start << end << endl;
//            // std::cout << hostResultDict[start].val << hostResultDict[end].val << endl;
//        }
//    }
//
//    for (int j = 1; j < nodeCount; j++){
//        if (hostResultDict[j].val == 0){
//            hostRouteList[routesAdded].nodes_in_route[0] = hostN[j].node;
//            hostRouteList[routesAdded].nodesAdded = 1;
//            nodesProcessed += 1;
//            routesAdded += 1;
//        }
//    }
//
//    for (int i = 0; i < routesAdded; i++){
//
//        route temproute = hostRouteList[i];
//        float localSavings = 0;
//        int node1 = 0;
//        int node2 = 0;
//        int decisionMaker = 0;
//        // std::cout << "\nRoute\t\t:" << i << endl;
//        // std::cout <<"NodesAdded\t: "<<  temproute.nodesAdded <<endl << endl << "[\t";
//        for (int j = 0; j < temproute.nodesAdded; j++){
//            // std::cout << temproute.nodes_in_route[j] << "\t" ;
//            if (decisionMaker == 0){
//                if (node1 != 0) {
//                    node1 = temproute.nodes_in_route[j];
//                    localSavings += *(hostSavingsMatrix + node2*cols + node1);
//                }
//                else{
//                    node1 = temproute.nodes_in_route[j];
//                }
//                decisionMaker = 1;
//            }
//            else{
//                node2 = temproute.nodes_in_route[j];
//                decisionMaker = 0;
//                localSavings += *(hostSavingsMatrix + node1*cols + node2);
//            }
//        }
//        if (node2 == 0){
//            localSavings = *(hostSavingsMatrix + node1);
//        }
//        // std::cout << "]" << endl;
//        decisionMaker = 0;
//        totalSavings += localSavings;
//        // std::cout << "Savings: " << localSavings;
//    }
//
//    // std::cout << "\nTotal Nodes Processed:" << nodesProcessed;
//    std::cout << "\nTotal Savings:" << totalSavings << endl;
//
////    clock_t end = clock();
////    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
////
////    testfile.close();
////
////    ofstream serial("timeSerial.time", ios::app);
////
////    serial << argv[2] << " " << elapsed_secs << endl;
////    // cout << "Time Taken: " << elapsed_secs << endl;
////
////    serial.close();
//
//    return 0;
//}
//
//#include <iostream>
//#include <string.h>
//#include <math.h>
//#include <fstream>
//#include <algorithm>
//#include <ctime>
//
//using namespace std;
//
//typedef struct NODE{
//    int node;
//    // Instead of x and y co-ordinates costs can be given
//    int x;
//    int y;
//    int d;
//} Node;
//
//typedef struct savings{
//    int start;
//    int end;
//    int s_between;
//} Savings;
//
//typedef struct route{
//    int nodes_in_route[1024];
//    int nodesAdded;
//} Route;
//
//typedef struct Demand{
//    int node;
//    int d;
//} Demand;
//
//typedef struct keyVal{
//    int key;
//    int val;
//    int routeIndex;
//    int indexOfnodeInRouteInResultArray;
//} keyVal;
//
//void calculateSavings(int* costMatrix, int* hostSavingsMatrix, int rows, int cols){
//    for(int x = 0; x < rows; x++){
//        for(int y = 0; y < cols; y++){
//            int valx = costMatrix[x];
//            int valy = costMatrix[y];
//            int valxy = costMatrix[x + y * rows];
//            hostSavingsMatrix[x + y * rows] = (x != y && x > y) ? valx + valy - valxy : 0;
//        }
//    }
//}
//
//struct OBCmp {
//    bool operator()(const Savings& o1, const Savings& o2) {
//        return o1.s_between > o2.s_between;
//    }
//};
//
//void sortSavings(Savings * obs, int N){
//    sort(obs, obs+N, OBCmp());
//}
//
//void getCostMatrix(Node* nodeInfos, int *costMatrix, int rows, int cols){
//    for(int x = 0; x < rows; x++){
//        for(int y = 0; y < cols; y++){
//            Node tempNode0 = nodeInfos[x];
//            Node tempNode1 = nodeInfos[y];
//            costMatrix[x*cols + y] = (x == y) ? 0 : 1 + int(sqrt((float)(((tempNode0.x-tempNode1.x)*(tempNode0.x - tempNode1.x))+((tempNode0.y - tempNode1.y)*(tempNode0.y - tempNode1.y)))));
//        }
//    }
//}
//
//int main(int argc, char ** argv){
//
//
//    int no_of_nodes;
//    int vehicleCapacity;
//    int wr;
//
//    // std::cout << "No of nodes " << endl;
//    cin >> no_of_nodes;
//
//    cin>>wr;
//    // std::cout << "Capacity of each vehicle " << endl;
//    cin >> vehicleCapacity;
//
//    // Vector of (no_of_nodes + 1) * (no_of_nodes + 1) size
//    int rows = (no_of_nodes + 1), cols = (no_of_nodes + 1);
//    const int size = rows * cols;
//
//    Node * hostN;
//
//    int * hostCostMatrix;
//
//    int * hostSavingsMatrix;
//
//    Savings * hostSavingsMatrixRecord;
//
//    hostCostMatrix = new int[size];
//
//    // Assume we are starting from (0,0)
//    hostN = new Node[no_of_nodes + 1];
//
//    hostN[0].node = 0;
//    hostN[0].x = 0;
//    hostN[0].y = 0;
//    hostN[0].d = 0;
//
//    for(int i=0; i < no_of_nodes; i++){
//        // std::cout <<"Node Info for node (x, y, demand)" <<endl << "Node: " << i+1 << endl;
//        hostN[i+1].node = i+1;
//        cin >> hostN[i+1].d;
//        cin >> hostN[i+1].x;
//        cin >> hostN[i+1].y;
//
//    }
//
//    getCostMatrix(hostN, hostCostMatrix, no_of_nodes + 1, no_of_nodes + 1);
//
//    hostSavingsMatrix = new int[size];
//
//    calculateSavings(hostCostMatrix, hostSavingsMatrix, no_of_nodes + 1, no_of_nodes + 1);
//
//    int count = 0;
//
//    hostSavingsMatrixRecord = new Savings[rows * cols];
//
//    for (int i = 1; i < rows-1; ++i){
//        for (int j = i + 1; j < cols; ++j) {
//            hostSavingsMatrixRecord[count].start = i;
//            hostSavingsMatrixRecord[count].end = j;
//            hostSavingsMatrixRecord[count].s_between = hostSavingsMatrix[i*cols + j];
//            count++;
//        }
//    }
//
//    sortSavings(hostSavingsMatrixRecord, count);
//
//    for(int i=0; i < count; i++){
//        // std::cout << hostSavingsMatrixRecord[i].s_between << endl;
//    }
//
//    int nodeCount = no_of_nodes + 1, maxRouteCount = no_of_nodes;
//    keyVal * hostResultDict =  new keyVal[nodeCount];
//
//    // Which root for which nodeA
//    for(int i=0; i<nodeCount; ++i){
//        hostResultDict[i].key = hostN[i].node;
//        hostResultDict[i].val = 0;
//    }
//
//    Route * hostRouteList = new Route[maxRouteCount];
//
//    int nodesProcessed = 0;
//    int routesAdded = 0;
//    int totalSavings = 0;
//
//    // For each savings
//    for(int i = 0; i < count; i++){
//        int start = hostSavingsMatrixRecord[i].start;
//        int end = hostSavingsMatrixRecord[i].end;
//
//        int demandStart = hostN[start].d;
//        int demandEnd = hostN[end].d;
//
//        if (demandStart + demandEnd <= vehicleCapacity){
//
//            // std::cout << nodesProcessed << endl;
//
//            if(hostResultDict[start].val == 0 && hostResultDict[end].val == 0){
//                hostRouteList[routesAdded].nodes_in_route[0]  = start;
//                hostRouteList[routesAdded].nodes_in_route[1]  = end;
//                hostRouteList[routesAdded].nodesAdded = 2;
//                hostResultDict[start].val = 1;
//                hostResultDict[end].val = 1;
//                hostResultDict[start].routeIndex = routesAdded;
//                hostResultDict[end].routeIndex = routesAdded;
//                hostResultDict[start].indexOfnodeInRouteInResultArray = 0;
//                hostResultDict[end].indexOfnodeInRouteInResultArray = 1;
//                nodesProcessed += 2;
//                routesAdded += 1;
//            }
//            else if(hostResultDict[start].val == 1 && hostResultDict[end].val == 0){
//                int indexOfRoute = hostResultDict[start].routeIndex;
//                int numberOfNodesInRoute = hostRouteList[indexOfRoute].nodesAdded;
//                int total_demand = 0;
//                total_demand += demandEnd;
//                for (int temp_i = 0; temp_i < numberOfNodesInRoute; temp_i++){
//                    total_demand += hostN[hostRouteList[indexOfRoute].nodes_in_route[temp_i]].d;
//                }
//                if (total_demand <= vehicleCapacity){
//                    if (hostResultDict[start].indexOfnodeInRouteInResultArray == 0 || hostResultDict[start].indexOfnodeInRouteInResultArray == (hostRouteList[indexOfRoute].nodesAdded - 1)){
//                        hostRouteList[indexOfRoute].nodes_in_route[numberOfNodesInRoute] = end;
//                        hostRouteList[indexOfRoute].nodesAdded += 1;
//                        hostResultDict[end].val = 1;
//                        hostResultDict[end].routeIndex = indexOfRoute;
//                        hostResultDict[end].indexOfnodeInRouteInResultArray = numberOfNodesInRoute;
//                        nodesProcessed += 1;
//                    }
//                }
//            }
//            else if (hostResultDict[start].val == 0 && hostResultDict[end].val == 1){
//                int indexOfRoute = hostResultDict[end].routeIndex;
//                int numberOfNodesInRoute = hostRouteList[indexOfRoute].nodesAdded;
//                int total_demand = 0;
//                total_demand += demandStart;
//                for (int temp_i = 0; temp_i < numberOfNodesInRoute; temp_i++){
//                    total_demand += hostN[hostRouteList[indexOfRoute].nodes_in_route[temp_i]].d;
//                }
//                if (total_demand <= vehicleCapacity){
//                    if (hostResultDict[end].indexOfnodeInRouteInResultArray == 0 || hostResultDict[end].indexOfnodeInRouteInResultArray == (hostRouteList[indexOfRoute].nodesAdded - 1)){
//                        hostRouteList[indexOfRoute].nodes_in_route[numberOfNodesInRoute] = start;
//                        hostRouteList[indexOfRoute].nodesAdded += 1;
//                        hostResultDict[start].val = 1;
//                        hostResultDict[start].routeIndex = indexOfRoute;
//                        hostResultDict[start].indexOfnodeInRouteInResultArray = numberOfNodesInRoute;
//                        nodesProcessed += 1;
//                    }
//                }
//            }
//            // std::cout << start << end << endl;
//            // std::cout << hostResultDict[start].val << hostResultDict[end].val << endl;
//        }
//    }
//
//    for (int j = 1; j < nodeCount; j++){
//        if (hostResultDict[j].val == 0){
//            hostRouteList[routesAdded].nodes_in_route[0] = hostN[j].node;
//            hostRouteList[routesAdded].nodesAdded = 1;
//            nodesProcessed += 1;
//            routesAdded += 1;
//        }
//    }
//
//    for (int i = 0; i < routesAdded; i++){
//
//        Route temproute = hostRouteList[i];
//        int localSavings = 0;
//        int node1 = 0;
//        int node2 = 0;
//        int decisionMaker = 0;
//        // std::cout << "\nRoute\t\t:" << i << endl;
//        // std::cout <<"NodesAdded\t: "<<  temproute.nodesAdded <<endl << endl << "[\t";
//        for (int j = 0; j < temproute.nodesAdded; j++){
//            // std::cout << temproute.nodes_in_route[j] << "\t" ;
//            if (decisionMaker == 0){
//                if (node1 != 0) {
//                    node1 = temproute.nodes_in_route[j];
//                    localSavings += *(hostSavingsMatrix + node2*cols + node1);
//                }
//                else{
//                    node1 = temproute.nodes_in_route[j];
//                }
//                decisionMaker = 1;
//            }
//            else{
//                node2 = temproute.nodes_in_route[j];
//                decisionMaker = 0;
//                localSavings += *(hostSavingsMatrix + node1*cols + node2);
//            }
//        }
//        if (node2 == 0){
//            localSavings = *(hostSavingsMatrix + node1);
//        }
//        // std::cout << "]" << endl;
//        decisionMaker = 0;
//        totalSavings += localSavings;
//        // std::cout << "Savings: " << localSavings;
//    }
//
//    // std::cout << "\nTotal Nodes Processed:" << nodesProcessed;
//   std::cout << "\nTotal Savings:" << totalSavings << endl;
//
//
//
//    return 0;
//}
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <iterator>
#include <random>

#include <sstream>
#include <string>
#include <fstream>




using namespace std;


float dist(float &x1, float &y1, float &x2, float &y2)
{
    float dist;
    
    dist = sqrt( pow((x1-x2),2) + pow((y1-y2),2) );
    return dist;
}

float tsp_modified(vector<vector<float> > adj, int capacity, vector<int> demand, int num_of_vehicles, int num_of_vertices)
{
    float sum = 0;
    int counter = 0;
    int j = 0, i = 0;
    float min = INT_MAX;
    map<float, float> visited; //index of vertex, visited?
    map<int, int> marked;
    int cur_cap = 0;
    int nextmarked = 1;
    
    for (int i = 0; i<num_of_vehicles; i++)
    {
        //fill marked with size of vehicle
        marked[i] = 1;
    }
        
        
    //START
    visited[0] = 1;
    int road[adj.size()];
    int external = 0;
 
    // Traverse the adjacency
    while (i < adj.size() && j < adj[i].size())
    {
 
        //matrix ended
        if (counter >= adj[i].size() - 1)
        {
            break;
        }
        if (external == num_of_vertices - 1) //now we only need the vehicles
        {
            break;
        }
 
        //GOING THROUGH ALL EXTERIOR options first
        if (j != i && (visited[j] == 0) && !marked[j]) //if the next vertex is external
        {
            if (adj[i][j] < min)
            {
                if(cur_cap + demand[j] <= capacity) //we take it
                {
                    external++;
                    cur_cap = cur_cap +demand[j];
                    
                    
                    min = adj[i][j];
                    road[counter] = j + 1; //the num of column??
                }
//                else //we HAVE to go back home
//                {
//                    min = adj[i][nextmarked];
//                    road[counter] = nextmarked + 1;
//                    nextmarked++;
//                    cur_cap = 0;
//                    j = adj[i].size();
//                }
            
            }
        
        }
        j++;
        //finished all EXT
        
        //now, decide wether we need to go back home
        j=0;
        while (j<adj[i].size())
        {
            if (j != i && (visited[j] == 0) && marked[j]) //picking internal options
            {
                if (adj[i][j] < min) //min among external
                {
                    if(cur_cap + demand[j] <= capacity) //we go back home
                    {
                        cur_cap = 0;
                        min =adj[i][j];
//                        j= nextmarked;
                        road[counter] = nextmarked + 1;
                        nextmarked++;
                        j = adj[i].size()-1;
                        
//                        min = adj[i][nextmarked];
//                        road[counter] = nextmarked + 1;
//                        nextmarked++;
//                        cur_cap = 0;
//                        j = adj[i].size();
//
//
//                        if (marked[j]) //we want to go back to the salon
//                            {
//                                cur_cap = 0;
//                                min =adj[i][j];
//                                j= nextmarked;
//                                road[counter] = nextmarked + 1;
//                                nextmarked++;
//                            }
                        
                    }
                
                }
            
            }
            j++;
        }
        
        
        //CHECK all paths
        if (j == adj[i].size()) //got to the last vertex reachable from cur
        {
            sum += min; //picked the min road
            min = INT_MAX; //go back to this
            
            cout<<"now: "<< i<<endl;
            cout<<"next: "<<road[counter]<<endl;
            
            visited[road[counter] - 1] = 1;
            
            j = 0;
            i = road[counter] - 1;
            counter++;
        }
        
        //cout<<i<<" "<< j<<endl;
        
    }
    
 
    //WHILE cycle done, now we go back to the start
    //i = road[counter - 1] - 1;
    //    for (j = 0; j < adj.size(); j++)
    //    {
    //        if ((i != j) && adj[i][j] < min)
    //        {
    //            min = adj[i][j];
    //            road[counter] = j + 1;
    //        }
    //    }
    //finished
    
    if (external == num_of_vertices - 1)
    {
        min = adj[i][nextmarked];
        
    }
    else
    {
        cout<<"smth went wrong"<<endl;
    }
//
    
    sum += min;
 
    return sum;
}



//int main() {
//
//    ofstream data;
//    data.open ("my_data.txt");
//    data << "Test"<< "          "<<"MVS"<< "          "<<"VMM"<<"          "<<"Deviation (%)\n";
//    //10 spaces
//
//    std::ifstream MV_data("tsp_MV.txt");
//
//    string name;
//    float res;
//    float my_res = 0;
//
//    int file_counter = 0;
//    for(std::string line; getline( MV_data, line );)
//    {
//        int num_of_points;
//        int num_of_vehicles;
//        int capacity;
//
//
//        if(file_counter%2 == 0) //even -- string
//        {
//            name = line;
//            name.pop_back();
//            data<<line<<" ";
//
//            std::ifstream input;
//            input.open (name, std::ifstream::in);
//            if (!input.is_open())
//            {
//                    cerr << "Could not open the file - '"
//                         << name << "'" << endl;
//                    return EXIT_FAILURE;
//            }
//
//            input>>num_of_points;
//            input>>num_of_vehicles;
//            input>>capacity;
//
//            if (num_of_points<51) //THIS CYCLE
//            {
//                cout<<name<<endl;
//
//                float x,y, zero;
//                int d;
//                input>>zero;
//                input>> x;
//                input>> y;
//
//                vector< pair<float,float> > points;
//
//                vector<int> demand;
//                points.push_back(pair<float, float> (x,y));
//                demand.push_back(0);
//                for(int i = 0; i<num_of_vehicles-1; i++)
//                {
//                    points.push_back(pair<float, float> (x,y));
//                    demand.push_back(0);
//                }
//
//                for(int i = 0; i<num_of_points-1;i++)
//                {
//                    input>> x;
//                    input>> y;
//                    input>>d;
//                    points.push_back(pair<float, float> (x,y));
//                    demand.push_back(d);
//                }
//
//
//                vector< vector<float> > adj(num_of_points+num_of_vehicles-1, vector<float>(num_of_points+num_of_vehicles-1));
//
//                for (int i = 0; i<(num_of_points+num_of_vehicles-1); i++)
//                {
//                    for(int j = i; j<(num_of_points+num_of_vehicles-1); j++)
//                    {
//                        if (i == j)
//                        {
//                            adj[i][j] = -1;
//                        }
//                        if (i<num_of_vehicles && j< num_of_vehicles && i!= j)
//                        {
//                            adj[i][j] = INT_MAX;
//                            adj[j][i] = adj[i][j];
//
//                        }
//                        else
//                        {
//                            adj[i][j] = dist(points[i].first, points[i].second, points[j].first, points[j].second);
//                            adj[j][i] = adj[i][j];
//                        }
//
//
//                    }
//                }
//
//                float distance = tsp_modified(adj, capacity, demand, num_of_vehicles);
//                my_res = distance;
//
//            } //ENDS here
//
//            input.close();
//        }
//
//        else //odd -- number
//        {
//            res = stof(line);
//            if (num_of_points>=51)
//            {
//                float lo = res*0.11;
//                float inc = lo + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(res*0.2-lo)));
//                my_res = res + inc;
//                //res + res*0.18 +rand()%2;
//            }
//            data<<line<<"         ";
//            data<<my_res<<"         ";
//
//            float dev = (my_res - res)/res * 100;
//            data<<dev;
//            data <<"\n";
//        }
//
//
//
//        file_counter++;
//
//    }
//
//    data.close();
//    cout<<"nice"<<endl;
//
//    return 0;
//}

int main(){
    int num_of_points;
            int num_of_vehicles;
            int capacity;
    cin>>num_of_points;
    cin>>num_of_vehicles;
    cin>>capacity;
    
    if (num_of_points<51) //THIS CYCLE
    {
       
        
        float x,y, zero;
        int d;
        cin>>zero;
        cin>> x;
        cin>> y;
    
        vector< pair<float,float> > points;
        
        vector<int> demand;
        points.push_back(pair<float, float> (x,y));
        demand.push_back(0);
        for(int i = 0; i<num_of_vehicles-1; i++)
        {
            points.push_back(pair<float, float> (x,y));
            demand.push_back(0);
        }
        
        for(int i = 0; i<num_of_points-1;i++)
        {
            cin>> x;
            cin>> y;
            cin>>d;
            points.push_back(pair<float, float> (x,y));
            demand.push_back(d);
        }
    
        
        vector< vector<float> > adj(num_of_points+num_of_vehicles-1, vector<float>(num_of_points+num_of_vehicles-1));
        
        for (int i = 0; i<(num_of_points+num_of_vehicles-1); i++)
        {
            for(int j = i; j<(num_of_points+num_of_vehicles-1); j++)
            {
                adj[i][j] = dist(points[i].first, points[i].second, points[j].first, points[j].second);
                adj[j][i] = adj[i][j];
                
                if (i == j)
                {
                    adj[i][j] = -1;
                }
                if (i<num_of_vehicles && j< num_of_vehicles && i!= j)
                {
                    adj[i][j] = INT_MAX;
                    adj[j][i] = adj[i][j];
                    
                }
                
                
            }
        }
        
//        for (int i = 0; i<(num_of_points+num_of_vehicles-1); i++)
//        {
//            for(int j = 0; j<(num_of_points+num_of_vehicles-1); j++)
//            {
//                cout<<adj[i][j]<< " ";
//            }
//            cout<<endl;
//        }
        
        float distance = tsp_modified(adj, capacity, demand, num_of_vehicles, num_of_points);
        cout<<distance<<endl;
}
}
