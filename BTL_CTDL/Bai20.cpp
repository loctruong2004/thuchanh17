#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits> 

using namespace std ;

class Product {
public:
    string code;
    string name;
    string manufacturer;
    double price;
    int quantity;

    Product(const string& c, const string& n, const string& m, double p)
        : code(c), name(n), manufacturer(m), price(p), quantity(1) {}
};

class GroceryStore {
private:
    vector<Product> products;

public:
    void readManagementInfo(const string& filename);
    void writeManagementInfo(const string& filename);
    void addProduct(const Product& product);
    void displayProducts() const;
    void displayInventory() const;
};

void GroceryStore::readManagementInfo(const string& filename) {
    ifstream file(filename.c_str());           //1
    if (!file.is_open()) {                     // 1   
        cerr << "Không the mo file de doc.\n";
        return;   
    }

    products.clear();                         //n

    string code, name, manufacturer;          //3
    double price;                             //1 
    while (file >> code >> name >> manufacturer >> price) {
        products.push_back(Product(code, name, manufacturer, price));       // n 
    }

    file.close();         //1
    cout << "Doc thong tin quan ly thanh cong.\n";      //1
}            
// T() = O(n)
void GroceryStore::writeManagementInfo(const string& filename) {
    ofstream file(filename.c_str());
    if (!file.is_open()) {
        cerr << "Khong the mo file de ghi.\n";
        return;
    }

    for (vector<Product>::const_iterator it = products.begin(); it != products.end(); ++it) {
        file << it->code << " " << it->name << " "
             << it->manufacturer << " " << it->price << "\n";
    }

    file.close();
    cout << "Ghi thông tin quan ly thanh cong.\n";
}

void GroceryStore::addProduct(const Product& product) {
    products.push_back(product);
}

void GroceryStore::displayProducts() const {
    cout << "Danh sach cac mat hàng:\n";
    for (vector<Product>::const_iterator it = products.begin(); it != products.end(); ++it) {
        cout << "Ma hang: " << it->code
             << ", Ten hàng: " << it->name
             << ", Nha san xuat: " << it->manufacturer
             << ", Gia: " << it->price << "\n";
    }
}

void GroceryStore::displayInventory() const {
    cout << "So luong ton kho cua tung mat hang:\n";
    for (vector<Product>::const_iterator it = products.begin(); it != products.end(); ++it) {
        cout << "Ma hang: " << it->code
             << ", Ten hang: " << it->name
             << ", So luong ton kho: " << it->quantity << "\n";
    }
}

int main() {
    GroceryStore groceryStore;

    // Ð?c thông tin qu?n lý t? file
    groceryStore.readManagementInfo("bai20.txt");

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Hien thi danh sach mat hang\n";
        cout << "2. Hien thi ton kho\n";
        cout << "3. Them mat hang\n";
        cout << "4. Luu thong tin quan ly\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                groceryStore.displayProducts();
                break;
            case 2:
                groceryStore.displayInventory();
                break;
            case 3: {
			
			
				    string code, name, manufacturer;
				    double price;
				    cout << "Nhap ma hang: ";
				    cin >> code;
				    cout << "Nhap ten hang: ";
				    cin >> name;
				    cout << "Nhap nha san xuat: ";
				    cin >> manufacturer;
				
				    // X? lý l?i nh?p giá
				    while (!(cin >> price)) {
				        cin.clear();  // Xóa c? l?i
				        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Xóa b? dòng ch?a l?i
				        cout << "Gia phai là mot so. Nhap gia: ";
				    }
				
				    groceryStore.addProduct(Product(code, name, manufacturer, price));
				    break;
				}
            case 4:
                groceryStore.writeManagementInfo("bai20.txt");
                break;
            case 0:
                cout << "Ket thuc chuong trình.\n";
                break;
            default:
                cerr << "Lua chon khong hop le. Vui long nhap lai.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
