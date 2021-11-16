#ifndef ZAD1_NODE_H
#define ZAD1_NODE_H
class Node {
private:
    double x, y;

public:
    Node();
    Node(double x, double y);

    void display();

    void updateValue(double x, double y);

    friend double pointsDistance(Node a, Node b);
};

double pointsDistance(Node a, Node b);

#endif //ZAD1_NODE_H
