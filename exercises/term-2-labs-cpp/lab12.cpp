#include <iostream>

using namespace std;

struct node
{
	int key;
	node *parent;
	node *left;
	node *right;
};

struct findNode
{
	node *n;
	bool b;
};

node make_node(int value);
void add_node(int value, node *&root);
void preorder(node *root);
void postorder(node *root);
void inorder(node *root);
findNode find_node(node *root, int value);
node find_successor(node *n);
void delete_node(node *&root, node *del_node);
bool isEmpty(node *n);
int getInt();
void sciezka_node(node *root, int value);

int main()
{
	cout << "Drzewa BST" << endl;

	bool wyjscie = false;
    unsigned short zd;
    int value;
    node *root = nullptr;
    findNode temp;

    do{
        cout << "Podaj nr dzialania: \n"
             << "1)  - Sprawdzenie czy drzewo jest puste \n"   
             << "2)  - Dodanie nowego wezla do drzewa \n"      
             << "3)  - Sprawdzenie czy klucz jest w drzewie \n"
             << "4)  - Preorder \n"                            
             << "5)  - Inorder \n"                             
             << "6)  - Postorder \n"                           
             << "7)  - Usuniecie wezla z drzewa \n"            
             << "8)  - Usuniecie calego drzewa \n"             
             << "9)  - Sciezka do liczby \n"                   
             << "10) - Wjscie z programu \n"                   
             << ">>>>> ";
        cin >> zd;

        switch(zd){
            case 1:
                if(isEmpty(root))
                    cout << "Drzewo jest puste!" << endl;
                else
                    cout << "Drzewo czyms pelne!" << endl;
                break;
            case 2:
                value = getInt();

                if(!isEmpty(root)){
                    cout << "Inorder: ";
                    inorder(root);
                    cout << endl;
                }
                if (find_node(root, value).b){
                    cout << "Podana liczba juz jest w drzewie!" << endl;
                    break;
                }

                add_node(value, root);
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                if(!isEmpty(root)){
                    value = getInt();
                    if (find_node(root, value).b)
                        cout << "Podana liczba jest w drzewie!" << endl;
                    else
                        cout << "Podanej liczby nie ma w drzewie!" << endl;
                    break;
                }
                else
                    cout << "Drzewo jest puste!" << endl;
                break;
            case 4:
                if(!isEmpty(root)){
                    cout << "Preorder: ";
                    preorder(root);
                    cout << endl;
                }
                else
                    cout << "Drzewo jest puste!" << endl;
                break;
            case 5:
                if(!isEmpty(root)){
                    cout << "Preorder: ";
                    inorder(root);
                    cout << endl;
                }
                else
                    cout << "Drzewo jest puste!" << endl;
                break;
            case 6:
                if(!isEmpty(root)){
                    cout << "Preorder: ";
                    postorder(root);
                    cout << endl;
                }
                else
                    cout << "Drzewo jest puste!" << endl;
                break;
            case 7:
                if(!isEmpty(root)){

                    cout << "Inorder: ";
                    inorder(root);
                    cout << endl;

                    value = getInt();
                    temp  = find_node(root, value);
                    if (!temp.b){
                        cout << "Podanej liczby nie ma w drzewie!" << endl;
                        break;
                    }
                    else
                        delete_node(root, temp.n);
                    if(!isEmpty(root)){
                        cout << "Inorder: ";
                        inorder(root);
                        cout << endl;
                    }
                    else
                        cout << "Drzewo jest puste!" << endl;
                }
                else
                    cout << "Drzewo jest puste!" << endl;
                break;
            case 8:
                if(!isEmpty(root)){
                    while(!isEmpty(root))
                        delete_node(root, root);
                    cout << "Drzewo zostalo wyczscione!" << endl;
                }
                else
                    cout << "Drzewo jest puste!" << endl;
                break;
            case 9:
                if(!isEmpty(root)){
                    value = getInt();
                    sciezka_node(root, value);
                    break;
                }
                else
                    cout << "Drzewo jest puste!" << endl;
                break;
            case 10:
                wyjscie = true;
                break;
            default:
                break;
        }

    }while(wyjscie==false);



	return 0;
}

node make_node(int value)
{
	node *n = new node;
	n->key = value;
	n->parent = NULL;
	n->left = NULL;
	n->right = NULL;

	return *n;
}

void add_node(int value, node *&root)
{
	if (root == NULL)
	{
		root = new node;
		root->key = value;
		root->parent = NULL;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (value < root->key)
		{
			if (root->left != NULL)
				add_node(value, root->left);
			else
			{
				root->left = new node;
				root->left->key = value;
				root->left->parent = root;
				root->left->left = NULL;
				root->left->right = NULL;
			}
		}
		else
		{
			if (root->right != NULL)
				add_node(value, root->right);
			else
			{
				root->right = new node;
				root->right->key = value;
				root->right->parent = root;
				root->right->left = NULL;
				root->right->right = NULL;
			}
		}
	}
}

void preorder(node *root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->key << " ";
	}
}
void inorder(node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}
findNode find_node(node *root, int value)
{
	findNode fn;
	fn.n = NULL;
	fn.b = false;

	if (root != NULL)
	{
		if (root->key == value)
		{
			fn.n = root;
			fn.b = true;
		}
		else
		{
			if (value < root->key)
				return find_node(root->left, value);
			else
				return find_node(root->right, value);
		}
	}

	return fn;
}
node find_successor(node *n)
{
	node *tmp = n->right;

	while (tmp->left != NULL)
		tmp = tmp->left;

	return *tmp;
}
void delete_node(node *&root, node *del_node)
{
	node *temp1 = new node, *temp2 = new node;
    if((del_node->left == nullptr) || (del_node->right==nullptr))
        temp1 = del_node;
    else
        *temp1 = find_successor(del_node);
    if(temp1->left!=nullptr)
        temp2 = temp1->left;
    else
        temp2 = temp1->right;
    if(temp2!=nullptr)
        temp2->parent=temp1->parent;

    if(temp1->parent == nullptr)
        root = temp2;
    else
        if(temp1==temp1->parent->left)
            temp1->parent->left  = temp2;
        else
            temp1->parent->right = temp2;
    if(temp1!=del_node)
        del_node->key=temp1->key;

    delete temp1;
}
bool isEmpty(node *n)
{
	if (n == NULL)
		return true;
	else
		return false;
}

void sciezka_node(node *root, int value)
{
	if (root != NULL)
	{
		if (root->key == value)
			cout << root->key << " ";
		else
		{
			if (value < root->key)
			{
				cout << root->key << " ";
				sciezka_node(root->left, value);
			}
			else
			{
				cout << root->key << " ";
				sciezka_node(root->right, value);
			}
		}
	}
}

int getInt(){
    int i ;
    cout << "Podaj liczbe: ";
    cin >> i;
    return i;
}