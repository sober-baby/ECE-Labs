//constructors: called automatically when an object is created
//Person:: Person(){
//Person:: Person(string n, int a){
    class Node{
    private:
        int data;
        Node *next;
    public:
        Node(int a, Node* n){data = d; next = n;}
    }
    int main(){
        Node* xr = new Node(23, NULL);
        new Node;

    }
    //Node destructor
    ~Node(){
        delete next;
    }
    class List{
        private:
            Node *head;
        public:
            List(){head = NULL;}
            ~List(){if(head)delete head;} 
            insert(int d){
                head = new Node(d, head);
            }
    }
