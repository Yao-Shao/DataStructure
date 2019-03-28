typedef struct node_S Listnode_S;
typedef Listnode_S *pst_List;
struct node_S
{
    void *p_data;
    int l_type;
    Listnode_S *pst_next;
};

enum Type
{
    INT,
    DOUBLE,
    CHAR,
    STRING
};

typedef char *string;