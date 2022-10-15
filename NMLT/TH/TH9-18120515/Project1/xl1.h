
// BT 5.1
struct phanso{
	int tu, mau;
};
void nhap(phanso &ps);
phanso rutgon(phanso ps);
phanso tong(phanso ps1, phanso ps2);
phanso hieu(phanso ps1, phanso ps2);
phanso tich(phanso ps1, phanso ps2);
phanso thuong(phanso ps1, phanso ps2);

// BT 5.2
struct coordinate{
	int x, y;
};

struct triangle{
	coordinate d1, d2, d3;
};

void nhap(triangle &t);
coordinate vector(coordinate a, coordinate b);
float lenvector(coordinate a, coordinate b);
bool kttg(triangle t);
float area(triangle t);
float perimeter(triangle t);


// BT 5.3

struct NGAY{
	int ngay, thang, nam;
};


struct span{
	float ngay, thang, nam;
};

bool ktngay(NGAY d);
void nhap(NGAY &d);
span khoangcach(NGAY d1, NGAY d2);
bool namnhuan(NGAY d);
NGAY homqua(NGAY d);
NGAY homsau(NGAY d);
NGAY truock(NGAY d, int k);
NGAY sauk(NGAY d, int k);
