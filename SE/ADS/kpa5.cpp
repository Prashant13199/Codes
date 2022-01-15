
#include<iostream>
#define MAX 20
#define MAX2 10
using namespace std;

class Queue
{
    int data[30];
    int R,F;
public:
    Queue()
    {
        R=F=-1;
    }
    void init()
    {
        R=F=-1;
    }
    int check_empty()
    {
        if(R==-1)
            return 1;
        return 0;
    }
    void insert_data(int x)
    {
        if(check_empty())
            R=F=0;
        else
            R+=1;
        data[R]=x;
    }
    int delete_data()
    {
        int x=data[F];
        if(R==F)
            init();
        else
            F=F+1;

        return (x);
    }
};

class node
{
    node *next;
    int vertex;
public:
    node()
    {
        vertex=0;
        next = NULL;
    }
    void set_vertex(int v)
    {
        vertex=v;
    }
    void set_next(node *n)
    {
        next=n;
    }
    int get_vertex()
    {
        return vertex;
    }
    node* get_next()
    {
        return next;
    }
};

class adj_list
{
    node *List[20];                     //heads of linked list
    int visited[20];
    int n;
public:
    adj_list()
    {
        for(int i=0;i<20;i++)
        {
            visited[i]=0;
        }
    }
    void read_graph();                  //create adjacency list
    void insert_in_list(int,int);       //insert an edge (vi,vj)
    void DFS(int);
    void BFS(int);
};

void adj_list::read_graph()
{
    int vi,vj,no_of_edges;
    cout<<"\n\tEnter no of vertices : ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        List[i]=NULL;
    }

    cout<<"\n\tEnter no of edges : ";
    cin>>no_of_edges;

    for(int j=0;j<no_of_edges;j++)
    {
        cout<<"\n\tEnter an edge (u,v) : ";
        cin>>vi>>vj;
        insert_in_list(vi,vj);
    }
}

void adj_list::insert_in_list(int vi,int vj)
{
    node *temp1,*temp2;
    temp2 = new node();
    temp2->set_vertex(vj);

    if(List[vi]==NULL)
        List[vi]=temp2;
    else
    {
        temp1=List[vi];
        while(temp1->get_next()!=NULL)
            temp1=temp1->get_next();
        temp1->set_next(temp2);
    }
}
void adj_list::DFS(int i)
{
    node *p;
    cout<<"\t=> "<<i;
    p = List[i];
    visited[i] = 1;
    while(p!=NULL)
    {
        i=p->get_vertex();
        if(!visited[i])
            DFS(i);
        p=p->get_next();
    }
}

void adj_list::BFS(int v)
{
    int visited[MAX],w;
    Queue q;
    node *p;
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    q.insert_data(v);
    cout<<"\t=> "<<v;
    visited[v]=1;
    while(!q.check_empty())
    {
        v=q.delete_data();
        for(p=List[v];p!=NULL;p=p->get_next())
        {
            w=p->get_vertex();
            if(visited[w]==0)
            {
                q.insert_data(w);
                visited[w]=1;
                cout<<"\t=> "<<w;
            }
        }
    }
}

class adj_matrix
{
    int matrix[10][10],visited[10],n;
public:
    void insert_data();
    void DFS(int);
    void BFS(int);
};

void adj_matrix::insert_data()
{
    cout<<"\n\tEnter no of vertices : ";
    cin>>n;

    cout<<"\n\tEnter adjacency matrix of graph : \n";
    for(int i=0;i<n;i++)
    {
        cout<<"\t";
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }

    for(int i=0;i<n;i++)
        visited[i]=0;
}
void adj_matrix::DFS(int i)
{
    int j;
    cout<<"\t=> "<<i;
    visited[i]=1;
    for(j=0;j<n;j++)
        if(!visited[j] && matrix[i][j]==1)
        DFS(j);
}

void adj_matrix::BFS(int v)
{
    int visited[MAX2];
    Queue q;
    for(int i=0;i<n;i++)
        visited[i]=0;
    q.insert_data(v);
    cout<<"\t=> "<<v;
    visited[v]=1;
    while(!q.check_empty())
    {
        v=q.delete_data();
        for(int i=0;i<n;i++)
            if(visited[i]==0 && matrix[v][i]!=0)
            {
                q.insert_data(i);
                visited[i]=1;
                cout<<"\t=> "<<i;
            }
    }
}

int main()
{
    adj_list obj1;
    adj_matrix obj2;
    bool main_ans=1;
    do
    {
        cout<<"\n\n\t\t\tGRAPH\n\n";
        cout<<"\n\tMENU : ";
        cout<<"\n\t\t1.Adjacency List\n\t\t2.Adjacency Matrix\n\t\t3.Exit\n";
        cout<<"\n\tEnter choice : ";
        char main_choice;
        cin>>main_choice;

        switch(main_choice)
        {
        case '1':
        {
            bool ans1=1;
            do
            {
                cout<<"\n\n\t\t\tADJACENCY LIST IMPLEMENTATION\n";
                cout<<"\n\tMENU:\n\t\t1.Create Graph\n\t\t2.Display Graph\n\t\t3.Exit\n";
                cout<<"\n\tEnter your choice : ";
                char choice;
                cin>>choice;

                switch(choice)
                {
                case '1':
                    obj1.read_graph();
                    break;
                case '2':
                        cout<<"\n\tChoice ::\n\t\t1.DFS\n\t\t2.BFS\n";
                        char opt;
                        cout<<"\n\tOption : ";
                        cin>>opt;

                        switch(opt)
                        {
                        case '1':
                            cout<<"\n\tDFS traversal of adjacency list :: ";
                            cout<<"\n";
                            obj1.DFS(0);
                            break;
                        case '2':
                            cout<<"\n\tBFS traversal of adjacency list :: ";
                            cout<<"\n";
                            obj1.BFS(0);
                            break;
                        default:
                            cout<<"\n\tEnter a valid Option\n";
                        }

                    break;
                case '3':
                    ans1=0;
                    break;
                default:
                    cout<<"\n\tPlease enter a valid choice\n";
                }
            }while(ans1);

            break;
        }
        case '2':
        {
            bool ans2=1;
            do
            {
                cout<<"\n\n\t\t\tADJACENCY MATRIX IMPLEMENTATION\n";
                cout<<"\n\tMENU:\n\t\t1.Create Graph\n\t\t2.Display Graph\n\t\t3.Exit\n";
                cout<<"\n\tEnter your choice : ";
                char choice2;
                cin>>choice2;

                switch(choice2)
                {
                case '1':
                    obj2.insert_data();
                    break;
                case '2':
                        cout<<"\n\tChoice ::\n\t\t1.DFS\n\t\t2.BFS\n";
                        char opt;
                        cout<<"\n\tOption : ";
                        cin>>opt;

                        switch(opt)
                        {
                        case '1':
                            cout<<"\n\tDFS traversal of adjacency matrix :: ";
                            cout<<"\n";
                            obj2.DFS(0);
                            break;
                        case '2':
                            cout<<"\n\tBFS traversal of adjacency matrix :: ";
                            cout<<"\n";
                            obj2.BFS(0);
                            break;
                        default:
                            cout<<"\n\tEnter a valid Option\n";
                        }

                    break;
                case '3':
                    ans2=0;
                    break;
                default:
                    cout<<"\n\tPlease enter a valid choice\n";
                }
            }while(ans2);

            break;
        }
        case '3':
            main_ans=0;
            break;
        default:
            cout<<"\n\tPlease enter a valid choice\n";
        }
    }while(main_ans);

    return 0;
}





