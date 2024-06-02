#include <stdio.h> 
#include <stdlib.h>

// 최대 Vertex의 수는 10개
#define MAX_VERTICES 10 

typedef struct Node { 
    int vertex; 
    // 다음 노드를 가리키는 next 포인터
    struct Node* next; 
} Node;

typedef struct Graph {
    // 인접 리스트(Adjacency List)를 나타내는 adjList 배열
    Node* adjList[MAX_VERTICES]; 
    // 방문 여부를 표시하는 visited 배열
    int visited[MAX_VERTICES]; 
} Graph;

// Graph를 생성하는 createGraph 함수
Graph* createGraph(); 
// Vertex를 추가하는 addVertex 함수
void addVertex(Graph* graph, int vertex); 
// Edge를 추가하는 addEdge 함수 
void addEdge(Graph* graph, int src, int dest); 
// Graph를 출력하는 printGraph 함수 
void printGraph(Graph* graph); 
// 깊이 우선 탐색을 하는 DFS(Depth-First Search) 함수 
void DFS(Graph* graph, int startVertex);
// 너비 우선 탐색을 하는 BFS(Breadth-First Search) 함수  
void BFS(Graph* graph, int startVertex); 
// Node를 생성하는 createNode 함수
Node* createNode(int vertex);
// 방문 여부를 초기화하는 clearVisited 함수
void clearVisited(Graph* graph);

int main() {
    printf("[----- 서범교 2021039042 -----]\n\n");

    Graph* graph = createGraph(); 
    char command; 
    int vertex, search, destination;

    do {
        printf("----------------------------------------------------------------\n");
        printf("                     Graph Searches                             \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Graph    = z \n");
        printf(" Insert Vertex       = v           Insert Edge          = e \n");
        printf(" Depth First Search  = d           Breath First Search  = b\n");
        printf(" Print Graph         = p           Quit                 = q\n");
        printf("----------------------------------------------------------------\n");

        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command) {
        case 'z': case 'Z':
            graph = createGraph();
            printf("Graph initialized.\n");
            break;
        case 'v': case 'V':
            printf("Enter vertex (0-9): ");
            scanf("%d", &vertex);
            if (vertex < 0 || vertex >= MAX_VERTICES) {
                printf("Invalid vertex number.\n");
            }
            else {
                addVertex(graph, vertex);
            }
            break;
        case 'e': case 'E':
            printf("Enter source and destination vertices (0-9): ");
            scanf("%d %d", &search, &destination);
            if (search < 0 || search >= MAX_VERTICES || destination < 0 || destination >= MAX_VERTICES) {
                printf("Invalid vertex numbers.\n");
            }
            else {
                addEdge(graph, search, destination);
            }
            break;
        case 'd': case 'D':
            printf("Enter start vertex for DFS (0-9): ");
            scanf("%d", &vertex);
            if (vertex < 0 || vertex >= MAX_VERTICES) {
                printf("Invalid vertex number.\n");
            }
            else {
                clearVisited(graph);
                DFS(graph, vertex);
                printf("\n");
            }
            break;
        case 'b': case 'B':
            printf("Enter start vertex for BFS (0-9): ");
            scanf("%d", &vertex);
            if (vertex < 0 || vertex >= MAX_VERTICES) {
                printf("Invalid vertex number.\n");
            }
            else {
                clearVisited(graph);
                BFS(graph, vertex);
                printf("\n");
            }
            break;
        case 'p': case 'P':
            printGraph(graph);
            break;
        case 'q': case 'Q':
            break;
        default:
            printf("Invalid command.\n");
        }
    } while(command != 'q' && command != 'Q');
    
    return 1;
}

// Graph를 생성하는 createGraph 함수 정의
Graph* createGraph() {
    // Graph 구조체의 크기만큼 동적 메모리 할당
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    
    for (int i = 0; i < MAX_VERTICES; i++) {     
        // 아직 방문하지 않은 정점을 나타내는 visited 배열 초기화
        graph->visited[i] = 0; 
        // 인접 리스트를 나타내는 adjList 배열 초기화
        graph->adjList[i] = NULL;
    }
    return graph; 
}

// Node를 생성하는 createNode 함수 정의
Node* createNode(int vertex) {   
    // Node 구조체의 크기만큼 동적 메모리 할당
    Node* newNode = (Node*) malloc(sizeof(Node)); 

    // newNode의 vertex에 vertex 할당
    newNode->vertex = vertex; 
    // newNode의 next에 NULL 할당
    newNode->next = NULL; 
    
    return newNode;
}

// Vertex를 추가하는 addVertex 함수 정의
void addVertex(Graph* graph, int vertex) {
    // 만약 인접 리스트가 비어있으면
    if (graph->adjList[vertex] == NULL){ 
        // vertex를 생성하고 graph의 adjList[vertex]에 할당
        graph->adjList[vertex] = createNode(vertex); 
        // vertex가 추가되었음을 출력
        printf("Vertex %d added.\n", vertex);
    }
    else {
        // 이미 존재하는 vertex임을 출력
        printf("Vertex %d already exists.\n", vertex); 
    }
}

// Edge를 추가하는 addEdge 함수 정의
void addEdge(Graph* graph, int src, int dest) {
    // dest를 생성하고 newNode에 할당
    Node* newNode = createNode(dest);
    // src의 인접 리스트에 newNode 추가
    Node* temp = graph->adjList[src]; 

    // src의 인접 리스트가 비어있으면
    if (temp == NULL) {
        // newNode를 src의 인접 리스트에 할당
        graph->adjList[src] = newNode; 
    }
    else {
        // 다음 노드가 없을 때까지 반복
         while (temp->next != NULL) {
            // temp를 다음 노드로 이동
            temp = temp->next;
        }
        // newNode를 temp의 다음 노드로 추가
        temp->next = newNode;
    }
    
    // src -> dest 간선 추가
    printf("Edge added from %d to %d.\n", src, dest);

    // dest를 생성하고 newNode에 할당
    newNode = createNode(src);
    // dest의 인접 리스트에 newNode 추가
    temp = graph->adjList[dest];
    
    // dest의 인접 리스트가 비어있으면
    if (temp == NULL) {
        // newNode를 dest의 인접 리스트에 할당
        graph->adjList[dest] = newNode;
    }
    else {
        // 다음 노드가 없을 때까지 반복
        while (temp->next != NULL) {
            // temp를 다음 노드로 이동
            temp = temp->next;
        }
        // newNode를 temp의 다음 노드로 추가
        temp->next = newNode;
    }
    printf("Edge added from %d to %d.\n", dest, src);
}

// Graph를 출력하는 printGraph 함수 정의
void printGraph(Graph* graph) {
    
    // 모든 vertex에 대해 인접 리스트 출력
    for (int i = 0; i < MAX_VERTICES; i++) {
        // graph의 adjList[i]에 할당된 temp
        Node* temp = graph->adjList[i];
        // temp가 NULL이 아닐 때까지 반복
        if (temp != NULL) {
            // vertex 출력
            printf("Vertex %d: ", i);
            
            // temp가 NULL이 아닐 때까지 반복
            while (temp != NULL) {
                // vertex 출력
                printf("%d -> ", temp->vertex); 
                // temp를 다음 노드로 이동
                temp = temp->next; 
            }
            printf("NULL\n");
        }
    }
}

// 깊이 우선 탐색을 하는 DFS(Depth-First Search) 함수 정의
void DFS(Graph* graph, int vertex) {
    // 만약 graph가 비어있으면
    if (graph == NULL) {
        printf("Graph is empty.\n"); 
        return; 
    }

    // vertex의 인접 리스트
    Node* adjList = graph->adjList[vertex];
    // temp에 adjList 할당
    Node* temp = adjList; 

    // vertex 방문
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    // temp가 NULL이 아닐 때까지 반복
    while (temp != NULL) {
        // 연결된 vertex
        int connectedVertex = temp->vertex;
        // 만약 방문하지 않은 vertex라면
        if (graph->visited[connectedVertex] == 0) {
            // DFS 함수 호출
            DFS(graph, connectedVertex);
        }
        // temp를 다음 노드로 이동
        temp = temp->next; 
    }
}

// 너비 우선 탐색을 하는 BFS(Breadth-First Search) 함수 정의
void BFS(Graph* graph, int startVertex) {
    // 만약 graph가 비어있으면
    if (graph == NULL) {
        printf("Graph is empty.\n"); 
        return;
    }

    // 큐를 나타내는 queue 배열
    Node* queue[MAX_VERTICES]; 
    // front와 rear를 나타내는 변수
    int front = 0; 
    int rear = 0; 

    // startVertex 방문
    graph->visited[startVertex] = 1;
    // startVertex를 queue에 추가 
    queue[rear++] = graph->adjList[startVertex]; 

    // front가 rear보다 작을 때까지 반복
    while (front < rear) {
        // queue의 front에 있는 vertex
        Node* current = queue[front++];
        // current의 vertex 출력
        printf("%d ", current->vertex); 

        // current의 인접 리스트
        Node* temp = graph->adjList[current->vertex];

        // temp가 NULL이 아닐 때까지 반복
        while (temp != NULL) {
            // 인접 vertex
            int adjVertex = temp->vertex;

            // 만약 방문하지 않은 vertex라면
            if (graph->visited[adjVertex] == 0) {
                // 인접 vertex 방문을 표시
                graph->visited[adjVertex] = 1;
                // 인접 vertex를 queue에 추가 
                queue[rear++] = graph->adjList[adjVertex]; 
            }
            // temp를 다음 노드로 이동
            temp = temp->next; 
        }
    }
}

// 방문 여부를 초기화하는 clearVisited 함수 정의
void clearVisited(Graph* graph) {
    // 모든 vertex에 대해 방문 여부 초기화
    for (int i = 0; i < MAX_VERTICES; i++) {
        // 방문하지 않은 vertex로 초기화
        graph->visited[i] = 0;
    }
}