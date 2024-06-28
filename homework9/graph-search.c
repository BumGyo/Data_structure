#include <stdio.h> 
#include <stdlib.h>

// �ִ� Vertex�� ���� 10��
#define MAX_VERTICES 10 

typedef struct Node { 
    int vertex; 
    // ���� ��带 ����Ű�� next ������
    struct Node* next; 
} Node;

typedef struct Graph {
    // ���� ����Ʈ(Adjacency List)�� ��Ÿ���� adjList �迭
    Node* adjList[MAX_VERTICES]; 
    // �湮 ���θ� ǥ���ϴ� visited �迭
    int visited[MAX_VERTICES]; 
} Graph;

// Graph�� �����ϴ� createGraph �Լ�
Graph* createGraph(); 
// Vertex�� �߰��ϴ� addVertex �Լ�
void addVertex(Graph* graph, int vertex); 
// Edge�� �߰��ϴ� addEdge �Լ� 
void addEdge(Graph* graph, int src, int dest); 
// Graph�� ����ϴ� printGraph �Լ� 
void printGraph(Graph* graph); 
// ���� �켱 Ž���� �ϴ� DFS(Depth-First Search) �Լ� 
void DFS(Graph* graph, int startVertex);
// �ʺ� �켱 Ž���� �ϴ� BFS(Breadth-First Search) �Լ�  
void BFS(Graph* graph, int startVertex); 
// Node�� �����ϴ� createNode �Լ�
Node* createNode(int vertex);
// �湮 ���θ� �ʱ�ȭ�ϴ� clearVisited �Լ�
void clearVisited(Graph* graph);

int main() {
    printf("[----- ������ 2021039042 -----]\n\n");

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

// Graph�� �����ϴ� createGraph �Լ� ����
Graph* createGraph() {
    // Graph ����ü�� ũ�⸸ŭ ���� �޸� �Ҵ�
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    
    for (int i = 0; i < MAX_VERTICES; i++) {     
        // ���� �湮���� ���� ������ ��Ÿ���� visited �迭 �ʱ�ȭ
        graph->visited[i] = 0; 
        // ���� ����Ʈ�� ��Ÿ���� adjList �迭 �ʱ�ȭ
        graph->adjList[i] = NULL;
    }
    return graph; 
}

// Node�� �����ϴ� createNode �Լ� ����
Node* createNode(int vertex) {   
    // Node ����ü�� ũ�⸸ŭ ���� �޸� �Ҵ�
    Node* newNode = (Node*) malloc(sizeof(Node)); 

    // newNode�� vertex�� vertex �Ҵ�
    newNode->vertex = vertex; 
    // newNode�� next�� NULL �Ҵ�
    newNode->next = NULL; 
    
    return newNode;
}

// Vertex�� �߰��ϴ� addVertex �Լ� ����
void addVertex(Graph* graph, int vertex) {
    // ���� ���� ����Ʈ�� ���������
    if (graph->adjList[vertex] == NULL){ 
        // vertex�� �����ϰ� graph�� adjList[vertex]�� �Ҵ�
        graph->adjList[vertex] = createNode(vertex); 
        // vertex�� �߰��Ǿ����� ���
        printf("Vertex %d added.\n", vertex);
    }
    else {
        // �̹� �����ϴ� vertex���� ���
        printf("Vertex %d already exists.\n", vertex); 
    }
}

// Edge�� �߰��ϴ� addEdge �Լ� ����
void addEdge(Graph* graph, int src, int dest) {
    // dest�� �����ϰ� newNode�� �Ҵ�
    Node* newNode = createNode(dest);
    // src�� ���� ����Ʈ�� newNode �߰�
    Node* temp = graph->adjList[src]; 

    // src�� ���� ����Ʈ�� ���������
    if (temp == NULL) {
        // newNode�� src�� ���� ����Ʈ�� �Ҵ�
        graph->adjList[src] = newNode; 
    }
    else {
        // ���� ��尡 ���� ������ �ݺ�
         while (temp->next != NULL) {
            // temp�� ���� ���� �̵�
            temp = temp->next;
        }
        // newNode�� temp�� ���� ���� �߰�
        temp->next = newNode;
    }
    
    // src -> dest ���� �߰�
    printf("Edge added from %d to %d.\n", src, dest);

    // dest�� �����ϰ� newNode�� �Ҵ�
    newNode = createNode(src);
    // dest�� ���� ����Ʈ�� newNode �߰�
    temp = graph->adjList[dest];
    
    // dest�� ���� ����Ʈ�� ���������
    if (temp == NULL) {
        // newNode�� dest�� ���� ����Ʈ�� �Ҵ�
        graph->adjList[dest] = newNode;
    }
    else {
        // ���� ��尡 ���� ������ �ݺ�
        while (temp->next != NULL) {
            // temp�� ���� ���� �̵�
            temp = temp->next;
        }
        // newNode�� temp�� ���� ���� �߰�
        temp->next = newNode;
    }
    printf("Edge added from %d to %d.\n", dest, src);
}

// Graph�� ����ϴ� printGraph �Լ� ����
void printGraph(Graph* graph) {
    
    // ��� vertex�� ���� ���� ����Ʈ ���
    for (int i = 0; i < MAX_VERTICES; i++) {
        // graph�� adjList[i]�� �Ҵ�� temp
        Node* temp = graph->adjList[i];
        // temp�� NULL�� �ƴ� ������ �ݺ�
        if (temp != NULL) {
            // vertex ���
            printf("Vertex %d: ", i);
            
            // temp�� NULL�� �ƴ� ������ �ݺ�
            while (temp != NULL) {
                // vertex ���
                printf("%d -> ", temp->vertex); 
                // temp�� ���� ���� �̵�
                temp = temp->next; 
            }
            printf("NULL\n");
        }
    }
}

// ���� �켱 Ž���� �ϴ� DFS(Depth-First Search) �Լ� ����
void DFS(Graph* graph, int vertex) {
    // ���� graph�� ���������
    if (graph == NULL) {
        printf("Graph is empty.\n"); 
        return; 
    }

    // vertex�� ���� ����Ʈ
    Node* adjList = graph->adjList[vertex];
    // temp�� adjList �Ҵ�
    Node* temp = adjList; 

    // vertex �湮
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    // temp�� NULL�� �ƴ� ������ �ݺ�
    while (temp != NULL) {
        // ����� vertex
        int connectedVertex = temp->vertex;
        // ���� �湮���� ���� vertex���
        if (graph->visited[connectedVertex] == 0) {
            // DFS �Լ� ȣ��
            DFS(graph, connectedVertex);
        }
        // temp�� ���� ���� �̵�
        temp = temp->next; 
    }
}

// �ʺ� �켱 Ž���� �ϴ� BFS(Breadth-First Search) �Լ� ����
void BFS(Graph* graph, int startVertex) {
    // ���� graph�� ���������
    if (graph == NULL) {
        printf("Graph is empty.\n"); 
        return;
    }

    // ť�� ��Ÿ���� queue �迭
    Node* queue[MAX_VERTICES]; 
    // front�� rear�� ��Ÿ���� ����
    int front = 0; 
    int rear = 0; 

    // startVertex �湮
    graph->visited[startVertex] = 1;
    // startVertex�� queue�� �߰� 
    queue[rear++] = graph->adjList[startVertex]; 

    // front�� rear���� ���� ������ �ݺ�
    while (front < rear) {
        // queue�� front�� �ִ� vertex
        Node* current = queue[front++];
        // current�� vertex ���
        printf("%d ", current->vertex); 

        // current�� ���� ����Ʈ
        Node* temp = graph->adjList[current->vertex];

        // temp�� NULL�� �ƴ� ������ �ݺ�
        while (temp != NULL) {
            // ���� vertex
            int adjVertex = temp->vertex;

            // ���� �湮���� ���� vertex���
            if (graph->visited[adjVertex] == 0) {
                // ���� vertex �湮�� ǥ��
                graph->visited[adjVertex] = 1;
                // ���� vertex�� queue�� �߰� 
                queue[rear++] = graph->adjList[adjVertex]; 
            }
            // temp�� ���� ���� �̵�
            temp = temp->next; 
        }
    }
}

// �湮 ���θ� �ʱ�ȭ�ϴ� clearVisited �Լ� ����
void clearVisited(Graph* graph) {
    // ��� vertex�� ���� �湮 ���� �ʱ�ȭ
    for (int i = 0; i < MAX_VERTICES; i++) {
        // �湮���� ���� vertex�� �ʱ�ȭ
        graph->visited[i] = 0;
    }
}