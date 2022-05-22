// Tree.cpp
#include "Tree.h"
//  ÄÅĞÅÂÎ Ñ ÏĞßÌÛÌ ÎÁÕÎÄÎÌ

//	ÏÎËÓ×ÅÍÈÅ ÂÛÑÎÒÛ
int Tree::height(node* p) {
    if (p != NULL) return p->height;
    else return 0;

}

// ğàçíîñòü âûñîò ëåâîãî è ïğàâîãî ïîääåğåâüåâ
int Tree::bfactor(node* p) {
    return height(p->right) - height(p->left);
}

void Tree::fixHeight(node* p) {
    int heightLeft = height(p->left);
    int heightRight = height(p->right);
    if (heightLeft > heightRight)
        p->height = heightLeft + 1;
    else
        p->height = heightRight + 1;
}

//  ÏĞÀÂÛÉ ÏÎÂÎĞÎÒ ÂÎÊĞÓÃ Ğ
node* Tree::rotateRight(node* p) {
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

//  ËÅÂÛÉ ÏÎÂÎĞÎÒ ÂÎÊĞÓÃ Q
node* Tree::rotateLeft(node* q) {
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

//  ÁÀËÀÍÑÈĞÎÂÊÀ ÓÇËÀ Ğ
node* Tree::balance(node* p) {
    fixHeight(p);
    if (bfactor(p) == 2) {
        if (bfactor(p->right) < 0)
            p->right = rotateRight(p->right);
        return rotateLeft(p);
    }
    if (bfactor(p) == -2) {
        if (bfactor(p->left) > 0)
            p->left = rotateLeft(p->left);
        return rotateRight(p);
    }
    return p; // ÁÀËÀÍÑÈĞÎÂÊÀ ÍÅ ÍÓÆÍÀ
}

//  ÂÑÒÀÂÊÀ ÊËŞ×À K Â ÄÅĞÅÂÎ Ñ ÊÎĞÍÅÌ P
node* Tree::insert(node* p, clientTree k) {
    if (!p) return new node(k);
    if (k.pasport < p->key.pasport)
        p->left = insert(p->left, k);
    else if (k.pasport > p->key.pasport) {
        p->right = insert(p->right, k);
    }
    else {
        cout << " Îøèáêà. Òàêîé êëèåíò óæå ñóùåñòâóåò." << endl;
    }
    return balance(p);
}

//  ÄÎÁÀÂÈÒÜ ÊËÈÅÍÒÀ
void Tree::addKlitnt(clientTree k) {
    if (root == NULL) {
        root = new node(k);
    }
    else {
        root = insert(root, k);
    }
}

void Tree::deleteKlient(string pasport) {
    if (root == NULL) {
        root = remove(root, pasport);
    }
    else {
        root = remove(root, pasport);
    }
}

//  ÏÎÈÑÊÀ ÓÇËÀ Ñ ÌÈÍÈÌÀËÜÍÛÌ ÊËŞ×ÎÌ Â ÏÎÄÄÅĞÅÂÅ P
node* Tree::findMin(node* p) {
    return p->left ? findMin(p->left) : p;
}


//  ÓÄÀËÅÍÈÅ ÓÇËÀ Ñ ÌÈÍÈÌÀËÜÍÛÌ ÊËŞ×ÎÌ Â ÏÎÄÄÅĞÅÂÅ P
node* Tree::removeMin(node* p) {
    if (p->left == 0)
        return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}

// ÓÄÀËÅÍÈÅ ÈÇ ÄÅĞÅÂÀ ÊËÈÅÍÒÀ ÏÎ ÑÒĞÎÊÅ ÏÀÑÏÎĞÒÀ
node* Tree::remove(node* p, string k) {
    if (!p) return 0;
    if (k < p->key.pasport)
        p->left = remove(p->left, k);
    else if (k > p->key.pasport)
        p->right = remove(p->right, k);
    else //  k == p->key 
    {
        node* q = p->left;
        node* r = p->right;
        delete p;
        if (!r) return q;
        node* min = findMin(r);
        min->right = removeMin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

//  ÓÄÀËÅÍÈÅ ÂÑÅÃÎ ÄÅĞÅÂÀ
void Tree::removeAll() {
    while ((root->left != NULL) && (root->right != NULL)) {
        removeMin(root);
    }
    delete root;
    root = NULL;
}


//  ÏÎÈÑÊ ÊËÈÅÍÒÀ Â ÄÅĞÅÂÅ ÏÎ ÑÒĞÎÊÅ ÏÀÑÏÎĞÒÀ
void Tree::findCustomer(node* p, string a) {
    if (p != NULL) {
        if (p->key.pasport == a) {

                cout << " ÔÈÎ: " << p->key.FIO << endl
                << " Ïàñïîğò: " << p->key.pasport << endl
                << " Ãîä ğîæäåíèÿ: " << p->key.birthyear << endl
                << " Ìåñòî è äàòà âûäà÷è ïàñïîğòà: " << p->key.placeAndDate << endl
                << " Àäğåññ: " << p->key.address << endl;
        }
        findCustomer(p->left, a);
        findCustomer(p->right, a);
    }
}

void Tree::findCustomerLite(node* p, string a) {
    if (p != NULL) {
        if (p->key.pasport == a) {
            cout << " ÔÈÎ: " << p->key.FIO << endl
            << " Ïàñïîğò: " << p->key.pasport << endl;
        }
        findCustomerLite(p->left, a);
        findCustomerLite(p->right, a);
    }
}

//  ÏĞÎÂÅĞÊÀ ÅÑÒÜ ËÈ ÓÆÅ ÊËÈÅÍÒ Ñ ÒÀÊÈÌ ÏÀÑÏÎĞÒÎÌ
bool Tree::checkPasport(string a, node* p) {
    while (p != NULL) {
        if (a < p->key.pasport)
            p = p->left;
        else if (a > p->key.pasport) {
            p = p->right;
        }
        else {
            if (a == p->key.pasport) {
                return 1;
            }
        }
    }
    return 0;
}

//  ÂÑÏÎÌÎÃÀÒÅËÜÍÀß ÔÓÍÊÖÈß ÄËß ÏĞßÌÎÃÎ ÂÛÂÎÄÀ
void Tree::minShow(node* p) {
    if (p != NULL) {
        cout << " ÔÈÎ: " << setw(30) << p->key.FIO << setw(20) << "Ïàñïîğò: " << setw(20) << p->key.pasport << endl;
    }
    if (p->left != NULL) {
        minShow(p->left);
    }
    if (p->right != NULL) {
        minShow(p->right);
    }
}

//  ÂÛÂÎÄ ÂÑÅÕ ÊËÈÅÍÒÎÂ
void Tree::showKlient() {
    if (root == NULL) {
        cout << " Áàçà äàííûõ ïóñòà.\n";
    }
    else {
        minShow(root);
    }
}

//  ÏÎÈÑÊ ÊËÈÅÍÒÀ ÏÎ ÑÒĞÎÊÅ
void Tree::findKlientOnString(node* p, string str, bool &chek) {
    if (p != NULL) {
        if (findString(p->key.address, str) || findString(p->key.FIO, str)) {
            chek = true;
            cout <<" ÔÈÎ: "  << p->key.FIO << setw(15) << " Ïàñïîğò: "  << p->key.pasport << setw(15) << " Àäğåññ: " <<  p->key.address << endl;
        }
        if (p->left != NULL) {
            findKlientOnString(p->left, str, chek);
        }
        if (p->right != NULL) {
            findKlientOnString(p->right, str, chek);
        }
    }
}


bool Tree::findString(string str2, string str1) {
    int i, j;
    int len1 = str1.length();
    int len2 = str2.length();

    for (i = 0; i <= len2 - len1; i++) {
        for (j = 0; j < len1; j++)
            if (str2[i + j] != str1[j]) {
                break;
            }
        if (j == len1) {
            return true;
        }
    }
    return false;
}

