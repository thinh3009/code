#include<iostream>
using namespace std;
struct Node {
	int so_luong_toa;
	Node* next;
};
struct QueueB {
	Node* head;
	Node* tail;
};

void PutQueueB(QueueB& q, int x) {
	Node* data = new Node;
	data->so_luong_toa = x;
	data->next = NULL;
	if (q.head == NULL) q.head = q.tail = data;
	else
	{
		q.tail->next = data; q.tail = data;
	}
}

int GetQueueB(QueueB& q, int& giatri) {
	Node* data = new Node;
	if (q.head == NULL)
		return 0;
	else
	{
		data = q.head;
		giatri = data->so_luong_toa; q.head = q.head->next;
		delete data;
		return 1;
	}
}
int main()
{
	int n, i, j, t;
	int C[1000];
	QueueB B; B.head = B.tail = NULL;
	cout << "Nhap so toa o vi tri A: ";
	cin >> n;
	cout << "Nhap thu tu cac toa can xep o vi tri C:\n";
	for (i = 0; i < n; i++) {
		cin >> C[i];
	}
	for (j = 0, i = 1; i <= n; i++)
	{
		if (C[j] == i) j++;
		else
			PutQueueB(B, i);
		while (B.head != NULL && B.head->so_luong_toa == C[j])
		{
			GetQueueB(B, t);
			j++;
		}
	}
	if (j < n - 1) {
		cout << "Khong the sap xep!";
		exit(0);
	}
	else {
		cout << "Cac buoc thuc hien di chuyen cac toa nhu sau:\n";
	}
	for (j = 0, i = 1; i <= n; i++)
	{
		if (C[j] == i) {
			cout << "Chuyen toa so " << i << " tu A - > C\n"; j++;
		}
		else
		{
			PutQueueB(B, i);
			cout << "Chuyen toa so " << i << " tu A - > B\n";
		}
		while (B.head != NULL && B.head->so_luong_toa == C[j])
		{
			GetQueueB(B, t);
			cout << "Chuyen toa so " << t << " tu B - > C\n"; j++;
		}
	}
}