#include<iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int n,i,choose;

//kiem tra so nguyen
int check_interger(float n) {
    return (ceil(n) == floor(n)) ? 1 : 0;
}

//Nhap Mang
 void input(int arr[], int n){
    for ( i = 0; i < n; i++) {
    	float temp;
    	cout<<"So thu " << i +1 <<": ";
    	cin >> temp;
    	while(!check_interger(temp)){
    		cout<<"Vui long nhap so nguyen!"<<endl;
    		cout<<"So thu " << i +1 <<": ";
    		cin >> temp;
		}
    	arr[i]=temp;
	}
}

//Xuat mang
 void output(int arr[], int n){
    for( i = 0; i < n; i++){
	cout << arr[i]<<' ';  
}
    cout << endl;
}

//Count co x
	void count(int arr[], int n, int x){
		int countX=0;
		for(i=0; i<n; i++){
			if(arr[i]==x){
				countX = countX + 1;
				cout<<"=>>  So "<< x <<" xuat hien tai vi tri "<<i +1<<endl;
			}
		}
		
		if(countX!=0){
	        cout<<"=>>  So "<< x <<" xuat hien "<< countX <<" lan";
	    }else{
	        cout<<"Warning: Ohh no! Cannot find '" << x <<"' ...";
	    }
	}

//Delete 0
	void del0(int &n, int arr[]){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            arr[j]=arr[i];
            j++;
        }
    }
    n=j;
    output(arr,n);
}

//So nguyen to
bool KtraSNT(int p){
        if(p<=1) return false;
        for(int i=2;i<=sqrt(p); i++){
            if(p%i==0){
                return false;
            }
        }
        return true;
    }
    
void soNguyenTo(int n, int arr[]){

    int b[255], c[255],m=0,k=0;
    //tachmang
    for(int i=0;i<n;i++){
        if(KtraSNT(arr[i])){
            b[m]=arr[i];
            m++;
        }else{
            c[k]=arr[i];
            k++;
        }
    }
    //Gop mang
    for(int i = 0;i<m;i++){
    	arr[i]= b[i];
	}
    for(int i=m;i<n;i++){
    	arr[i]= c[i-m];
	}
	output(arr,n);
}

//3sum
void average3(int n, int a[]){

    int sum=0,d=0;
    for(int i=0;i<n;i++){
        if(a[i]%3==0){
            sum+=a[i];
            d++;
        }
    }

    if(sum==0){
        cout<<"Khong co so chia het cho 3!" <<endl;
    }else{
        cout<<"TBC so chia het cho 3 = " <<sum/d;
    }
}



//Main Menu
int main() {

	cout<<"-----------------------------------------"<<endl;
	cout<<"		BAI TAP CSLT 		"<<endl;
	float temp;
	bool check=false;
	do{
		cout<<"Nhap so luong so nguyen(toi da 100): ";
		cin>>temp;
		if(temp <= 1 || temp > 100 ||!check_interger(temp)){
			check=true;
		}else{
			check=false;
		}
		if(check){
			cout<<"Error!  ->>  Nhap so luong tu 2 tro len va toi da 100!!!"<<endl;
			cout<<endl;
		}
	}
	while(temp <= 1 || temp > 100 ||!check_interger(temp)) ;
	n=temp;
	cout<<">> So luong so nguyen can nhap:  " << n <<endl;
	
	int arr[n];
	cout<<endl;
    cout << "---------- Nhap cac phan tu: ----------\n";
	input(arr, n);
	cout<<endl;
//Hien thi
	cout<< ">> Day so ban vua nhap la:  ";
	output(arr, n);
	
//Vong lap Menu
	do{
		cout<<"\n\n------------------ MENU -------------------"<<endl;
		//Menu chuong trinh
		cout<<"1. Hien thi du lieu"<<endl;
		cout<<"2. Dem so lan xuat hien cua so X va vi tri "<<endl;
		cout<<"3. Xoa gia tri = '0' "<<endl;
		cout<<"4. Sap xep so nguyen to "<<endl;
		cout<<"5. Tinh trung binh cong so chia het cho 3 "<<endl;
		cout<<"0. Exit" <<endl;
		cout<<"-----------------------------------------"<<endl;
		cout<<"Enter a menu option in the Keyboard [1,2,3,4,5,0]"<<endl;
		
		//Choose Question
		cin >> choose;
		switch(choose){
			case 0:{
				cout<<"End!";
				break;
			}
			case 1:{
				cout<< ">> Du lieu mang hien tai:  ";
				output(arr, n);
				break;
			}
			case 2:{
				int x;
				cout <<"Nhap so can dem: ";
				cin >> x;
				count(arr,n,x);
				break;
			}
			case 3:{
				cout<< "=>  Mang sau khi xoa '0': " ;
				del0(n,arr);
                cout<<endl;
                break;
			}
			case 4:{
                soNguyenTo(n,arr);
                break;
            }
            case 5:{
            	average3(n,arr);
                cout<<endl;
				break;
			}
			default:
	        {
	            cout << "*** Data processing failed! ***" << endl;
	        }
		}
	} while(choose!=0);
	
}
