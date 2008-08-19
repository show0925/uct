#ifndef __UCT__
#define __UCT__

#include <vector>
#include "common.h"
#include "board.h"

class Node;

typedef std::vector<Node*> Nodes; //FIXME should be a list be implementation is easyer with vector
typedef std::vector<const Node*> ConstNodes;

class Node {
public:
    Node(); //root constructor
    Node(const Move *move,Node *father=NULL);
    ~Node();

    void print() const;
    void print_tree(int level=0) const;
    void print_best_branch_down() const;
    void print_branch_up() const;

    const Node *get_best_child() const;
    Token play_random_game(Board *board,Token player);

    Mode mode; //FIXME
    const Move *move;
protected:
    static void print_branch(const ConstNodes &branch);

    ConstNodes get_best_branch_down() const;
    ConstNodes get_branch_up() const;

    void update_father(Value value);
    void propagate_winning();
    void recompute_inheritance();
    void tell_granpa_dad_is_a_looser(const Node *dad);

private:
    Node *father;
    //Nodes good_children;
    Nodes children;
    Moves unexplored_moves;

    Count nb;
    Value value;
    Value simulation_value;

};

#endif