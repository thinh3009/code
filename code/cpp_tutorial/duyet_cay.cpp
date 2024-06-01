#include<iostream>
using namespace std;
// khai báo cấu trúc  1 cái node
struct node
{
    int data; // dữ liệu của node ==> dữ liệu mà node sẽ lưu trữ
    struct node *pLeft; // node liên kết bên trái của cây <=> cây con trái
    struct node *pRight; // node liên kết bên phải của cây <=> cây con phải
};
typedef struct node NODE;
typedef NODE* TREE;
 
// khởi tạo cây
void KhoiTaoCay(TREE &t)
{
    t = NULL; // cây rỗng
}
 
// hàm thêm phần tử x vào cây nhị phân
void ThemNodeVaoCay(TREE &t, int x)
{
    // nếu cây rỗng
    if (t == NULL)
    {
        NODE *p = new NODE; // khởi tạo 1 cái node để thêm vào cây
        p->data = x;// thêm dữ liệu x vào data
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;// node p chính là node gốc <=> x chính là node gốc
    }
    else // cây có tồn tại phần tử
    {
        // nếu phần tử thêm vào mà nhỏ hơn node gốc ==> thêm nó vào bên trái
        if (t->data > x)
        {
            ThemNodeVaoCay(t->pLeft, x); // duyệt qua trái để thêm phần tử x
        }
        else if (t->data < x) // nếu phần tử thêm vào mà lớn hơn node gốc ==> thêm nó vào bên phải
        {
            ThemNodeVaoCay(t->pRight, x); // duyệt qua phải để thêm phần tử x
        }
    }
}
 
// hàm xuất cây nhị phân theo NLR
void Duyet_NLR(TREE t)
{ 
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        cout << t->data << " "; // xuất dữ liệu trong node
        Duyet_NLR(t->pLeft); // duyệt qua trái
        Duyet_NLR(t->pRight); // duyệt qua phải
    }
}
 
// hàm xuất cây nhị phân theo NRL
void Duyet_NRL(TREE t)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        cout << t->data << " "; // xuất dữ liệu trong node
        Duyet_NRL(t->pRight); // duyệt qua phải 
        Duyet_NRL(t->pLeft); // duyệt qua trái
    }
}
 
// hàm xuất cây nhị phân theo LNR <=> xuất ra các phần tử từ bé đến lớn
void Duyet_LNR(TREE t)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        Duyet_LNR(t->pLeft); // duyệt qua trái
        cout << t->data << "  "; // xuất giá trị của node
        Duyet_LNR(t->pRight); // duyệt qua phải
    }
}
 
// hàm xuất cây nhị phân theo RNL <=> xuất ra các phần tử từ lớn đến bé
void Duyet_RNL(TREE t)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        Duyet_RNL(t->pRight); // duyệt qua phải
        cout << t->data << "  "; // xuất giá trị của node
        Duyet_RNL(t->pLeft); // duyệt qua phải
    }
}
 
// hàm xuất cây nhị phân theo LRN
void Duyet_LRN(TREE t)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        Duyet_LRN(t->pLeft); // duyệt qua trái
        Duyet_LRN(t->pRight); // duyệt qua phải
        cout << t->data << "  "; // xuất giá trị của node
    }
}
 
// hàm xuất cây nhị phân theo RLN
void Duyet_RLN(TREE t)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        Duyet_RLN(t->pRight); // duyệt qua phải
        Duyet_RLN(t->pLeft); // duyệt qua trái
        cout << t->data << "  "; // xuất giá trị của node
    }
}
 
 
// hàm nhập dữ liệu
void Menu(TREE &t)
{
    while (true)
    {
        cout << "\n\n\t\t =========== MENU ===========";
        cout << "\n1. Nhap du lieu cho cay: ";
        cout << "\n2. Duyet cay NLR";
        cout << "\n3. Duyet cay NRL";
        cout << "\n4. Duyet cay LNR";
        cout << "\n5. Duyet cay RNL";
        cout << "\n6. Duyet cay LRN";
        cout << "\n7. Duyet cay RLN";
        cout << "\n0. End";
        cout << "\n\n\t\t ============================";
 
        int luachon;
        cout << "\nNhap lua chon: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 7)
        {
            cout << "\nLua chon sai!!";
        }
        else if (luachon == 1)
        {
            int x;
            cout << "\nNhap so nguyen x: ";
            cin >> x;
            ThemNodeVaoCay(t, x);
        }
        else if (luachon == 2)
        {
            cout << "\nDuyệt cây theo NLR\n";
            Duyet_NLR(t);
        }
        else if (luachon == 3)
        {
            cout << "\nDuyệt cây theo NRL\n";
            Duyet_NRL(t);
        }
        else if (luachon == 4)
        {
            cout << "\nDuyệt cây theo LNR\n";
            Duyet_LNR(t);
        }
        else if (luachon == 5)
        {
            cout << "\nDuyệt cây theo RNL\n";
            Duyet_RNL(t);
        }
        else if (luachon == 6)
        {
            cout << "\nDuyệt cây theo LRN\n";
            Duyet_LRN(t);
        }
        else if (luachon == 7)
        {
            cout << "\nDuyệt cây theo RLN\n";
            Duyet_RLN(t);
        }
        else
        {
            break;
        }
    }
}
 
int main()
{
    TREE t;
    KhoiTaoCay(t);
    Menu(t);
 
    cout<<"\n-------------------------------------\n";
  
}