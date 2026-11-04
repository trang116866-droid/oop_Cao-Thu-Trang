#include<bits/stdc++.h>
using namespace std;
class Vehicle{
	private: 
		int vehicleID;
		std::string vehicleType;
		int entryTime;
		int parkingDuration;
		double parkingFee;
		bool isOccupied; 
	public:
		Vehicle(){
			vehicleID=0;
			vehicleType="";
			parkingDuration=0; 
			entryTime=0;
			parkingFee=0;
			isOccupied= false; 
		}
		Vehicle(int ID,string Type,int Time,int Duration ){
			vehicleID=ID;
			vehicleType=Type;
			entryTime=Time;
			parkingDuration=Duration;
		}
		string getVehicleType(){
			return vehicleType;
		}
		int getVehicleID(){
			return vehicleID;
		}
		void setvehicleID(int ID){
			if(ID<0){
				cout<<"Ma dinh danh khong hop le"; 
			}
		}
		void setvehicleType(string Type){
			if((Type!="Car" && Type!="Motocycle" && Type!="Bicycle") || (Type!="car"&& Type!="motorcycle"&& Type!="bicycle")){
				cout<<"Loai xe khong hop le!"; 
			}
			else{
				for(int i=0;i<Type.length();i++){
					if(isdigit(Type[i])){
						cout<<"Du lieu vao khong hop le";
						break; 
					} 
				} 
			} 
		}
		void setentryTime(int Time){
			if(Time<0 || Time >23)
				cout<<"Gio vao bai khong hop le"; 
		}
		void setparkingDuration(int Duration){
			if(Duration<1 && Duration >23){
				cout<<"Gio do khong hop le"; 
			} 
		}
		void setparkingFee(double Fee){
			if(Fee<0){
				cout<<"Phi do xe khong hop le";
			} 
		}
		double calculateFee(){
			if(vehicleType=="Car"||vehicleType=="car"){
				if((entryTime>=6 && entryTime<10) ||(entryTime>=15 && entryTime<19)){
					if(parkingDuration>0 && parkingDuration<=2){
						parkingFee=(6+0.3*6)*parkingDuration;
					}
					else{
						parkingDuration-=2;
						parkingFee=(6+0.3*6)*2+((6+0.3*6)-(6+6*0.3)*0.1)*parkingDuration;
					}
				}
				else{
					if(parkingDuration>0 && parkingDuration<=2){
						parkingFee=(6-0.05*6)*parkingDuration;
					}
					else{
						parkingDuration-=2;
						parkingFee=(6-0.05*6)*2+((6-0.05*6)-(6-0.05*6)*0.1)*parkingDuration;
					}
				}
			}
			else if(vehicleType=="Motorcycle"||vehicleType=="motorcycle"){
				if((entryTime>=6 && entryTime<10) ||(entryTime>=15 && entryTime<19)){
					if(parkingDuration>0 && parkingDuration<=2){
						parkingFee=(4+0.3*4)*parkingDuration;
					}
					else{
						parkingDuration-=2;
						parkingFee=(4+0.3*4)*2+((4+0.3*4)-(4+4*0.3)*0.1)*parkingDuration;
					}
				}
				else{
					if(parkingDuration>0 && parkingDuration<=2){
						parkingFee=(4-0.05*4)*parkingDuration;
					}
					else{
						parkingDuration-=2;
						parkingFee=(4-0.05*4)*2+((4-0.05*4)-(4-0.05*4)*0.1)*parkingDuration;
					}
				}
			}
			else{
				if((entryTime>=6 && entryTime<10) ||(entryTime>=15 && entryTime<19)){
					if(parkingDuration>0 && parkingDuration<=2){
						parkingFee=(2+0.3*2)*parkingDuration;
					}
					else{
						parkingDuration-=2;
						parkingFee=(2+0.3*2)*2+((2+0.3*2)-(2+2*0.3)*0.1)*parkingDuration;
					}
				}
				else{
					if(parkingDuration>0 && parkingDuration<=2){
						parkingFee=(2-0.05*2)*parkingDuration;
					}
					else{
						parkingDuration-=2;
						parkingFee=(2-0.05*2)*2+((2-0.05*2)-(2-0.05*2)*0.1)*parkingDuration;
					}
				}
			}
			return parkingFee;
		}
		void display(){
			cout<<vehicleID<<endl<<vehicleType<<endl<<entryTime<<endl<<parkingDuration<<endl<<parkingFee<<endl;
		} 
};
class ParkingLot{
	int parkID;
	char size;
	Vehicle vehicle1;
	Vehicle vehicle2;
	Vehicle vehicle3;
	bool hasVehicle1;
	bool hasVehicle2;
	bool hasVehicle3;
	public:
		ParkingLot(){
			parkID=0;
			size=' ';
		}
		ParkingLot(int pID,char pSize){
				parkID=pID;
				size=pSize;
				hasVehicle1=false;
				hasVehicle2=false;
				hasVehicle3=false;
		}
		int getParkID(){
			return parkID;
		}
		char getSize(){
			return size;
		}
		bool addVehicle(const Vehicle& v){
			if(hasVehicle1==true && hasVehicle2==true && hasVehicle3==true){
				cout<<"Bai do xe da day,khong the chua them";
			}
			else if(size=='S'|| size=='s'){
				if(hasVehicle1==false){
				vehicle1=v;
				hasVehicle1=true;
				return true; 
				} 
			}
			else if(size=='M'|| size=='m'){
				if(hasVehicle1==false){
					vehicle1=v;
					hasVehicle1=true;
					return true; 
				}
				else if(hasVehicle2==false){
					vehicle2=v;
					hasVehicle2=true;
					return true; 
				} 
			}
			else if(size=='L'|| size=='l'){
				if(hasVehicle1==false){
					vehicle1=v;
					hasVehicle1=true;
					return true; 
				}
				else if(hasVehicle2==false){
					vehicle2=v;
					hasVehicle2=true;
					return true; 
				}
				else if(hasVehicle3==false){
					vehicle3=v;
					hasVehicle3=true;
					return true; 
				} 
			}
			return false; 	
		}
		bool removeVehicle(int vID){
			if(hasVehicle1==true && vehicle1.getVehicleID()==vID ){
				hasVehicle1=false;
				return true; 
			}
			else if(hasVehicle2==true && vehicle2.getVehicleID()==vID){
				hasVehicle2=false;
				return true; 
			}
			else if(hasVehicle3==true&& vehicle3.getVehicleID()==vID){
				hasVehicle3=false;
				return true; 
			}
			return false; 
		}
		void displayLotInfor(){
			int ds;
			if(hasVehicle1==true){
				ds=1; 
			}
			else if(hasVehicle1==true && hasVehicle2==true){
				ds=2; 
			}
			else if(hasVehicle1==true && hasVehicle2==true && hasVehicle3==true){
				ds=3; 
			}
			cout<<parkID<<" "<<size<<" "<<ds;
		}
		void InformationVehicle(){
			if(hasVehicle1==true){
				vehicle1.display();
			}
			if(hasVehicle2==true){
				vehicle2.display();
			}
			if(hasVehicle3==true){
				vehicle3.display();
			}
		}
		void listVehicleType(string type){
			bool timkiem=false;
			if(hasVehicle1==true){
				if(vehicle1.getVehicleType()==type){
					cout<<"Parking lot"<<parkID<<endl;
					vehicle1.display();
					timkiem=true;			
				}
			}
			if(hasVehicle2==true){
				if(vehicle2.getVehicleType()==type){
					cout<<"Parking lot:"<<parkID<<endl;
					vehicle2.display();
					timkiem=true;
				}
			}
			if(hasVehicle3==true){
				if(vehicle3.getVehicleType()==type){
					cout<<"Parking lot:"<<parkID<<endl;
					vehicle3.display();
					timkiem=true;
				}
			}
			if(timkiem==false){
				cout<<"Khong tim thay xe"<<endl;
			}
		}
		void averageFee(){
			double phitbCar=0;
			double phitbBicycle=0;
			double phitbMotorcycle=0;
			int c=0;
			int m=0;
			int b=0;
			
			if(hasVehicle1==true){
				if(vehicle1.getVehicleType()=="car" || vehicle1.getVehicleType()=="Car"){
					phitbCar+=vehicle1.calculateFee();
					c++;
				}
				if(vehicle1.getVehicleType()=="Motorcycle" || vehicle1.getVehicleType()=="motorcycle"){
					phitbMotorcycle+=vehicle1.calculateFee();
					m++;
				}
				if(vehicle1.getVehicleType()=="Bicycle" || vehicle1.getVehicleType()=="bicycle"){
					phitbBicycle+=vehicle1.calculateFee();
					b++;
				}
			}
			if(hasVehicle2==true){
				if(vehicle2.getVehicleType()=="car" || vehicle2.getVehicleType()=="Car"){
					phitbCar+=vehicle2.calculateFee();
					c++;
				}
				if(vehicle2.getVehicleType()=="Motorcylce" || vehicle2.getVehicleType()=="motorcycle"){
					phitbMotorcycle+=vehicle2.calculateFee();
					m++;
				}
				if(vehicle2.getVehicleType()=="Bicycle" || vehicle2.getVehicleType()=="bicycle"){
					phitbBicycle+=vehicle2.calculateFee();
					b++;
				}
			}
			if(hasVehicle3==true){
				if(vehicle3.getVehicleType()=="car" || vehicle3.getVehicleType()=="Car"){
					phitbCar+=vehicle3.calculateFee();
					c++;
				}
				if(vehicle3.getVehicleType()=="Motorcylce" || vehicle3.getVehicleType()=="motorcycle"){
					phitbMotorcycle+=vehicle3.calculateFee();
					m++;
				}
				if(vehicle3.getVehicleType()=="Bicycle" || vehicle3.getVehicleType()=="bicycle"){
					phitbBicycle+=vehicle3.calculateFee();
					b++;
				}
			}
			double averageCar = 0;
			if (c > 0) {
    			averageCar = phitbCar / c;
			} else {
    			averageCar = 0;
			}
			double averageBicycle = 0;
			if (b > 0) {
    			averageBicycle = phitbBicycle / b;
			} else {
    			averageBicycle = 0;
			}
			double averageMotorcycle = 0;
			if (m > 0) {
    			averageMotorcycle = phitbMotorcycle / m;
			} else {
    			averageMotorcycle = 0;
			}	
			averageCar=phitbCar/c;
			averageMotorcycle=phitbMotorcycle/m;
			averageBicycle=phitbBicycle/b;
			cout<<averageCar<<endl<<averageBicycle<<endl<<averageMotorcycle<<endl;
		} 
};
class SystemInterface{
	private:
		ParkingLot parkingLot1;
		ParkingLot parkingLot2;
		ParkingLot parkingLot3;
		bool hasLot1;
		bool hasLot2;
		bool hasLot3;
	public:
		bool addLot(int pID,char pSize){
			if(parkingLot1.getParkID()==pID || parkingLot2.getParkID()==pID || parkingLot3.getParkID()==pID){
				cout<<"ID bai do bi trung";
			}
			if(hasLot1==true && hasLot2==true && hasLot3==true){
				cout<<"Da du bai do xe";
			}
			if(hasLot1==false){
				parkingLot1=ParkingLot(pID,pSize);
				hasLot1=true;
				return true;
			}
			else if(hasLot2==false){
				parkingLot2=ParkingLot(pID,pSize);
				hasLot2=true;
				return true;
			}
			else if(hasLot3==false){
				parkingLot3=ParkingLot(pID,pSize);
				hasLot3=true;
				return true;
			}
			else return false;
		}
		bool removeLot(int pID){
			if(hasLot1==true && parkingLot1.getParkID()==pID){
				hasLot1=false;
				return true;
			}
			else if(hasLot2==true && parkingLot2.getParkID()==pID){
				hasLot2=false;
				return true;
			}
			else if(hasLot3==true && parkingLot3.getParkID()==pID){
				hasLot3=false;
				return true;
			}
			else return false;
		}
		void listVehicletype(string type){
			if(hasLot1==true){
				parkingLot1.listVehicleType(type);
			}
			if(hasLot2==true){
				parkingLot2.listVehicleType(type);
			}
			if(hasLot3==true){
				parkingLot3.listVehicleType(type);
			}
		}
		void informationVehicle(int parkID){
			if(parkingLot1.getParkID()==parkID){
				parkingLot1.InformationVehicle();
			}
			if(parkingLot2.getParkID()==parkID){
				parkingLot2.InformationVehicle();
			}
			if(parkingLot3.getParkID()==parkID){
				parkingLot3.InformationVehicle();
			}
		}
		void AverageFee(){
			if(hasLot1==true){
				parkingLot1.averageFee();
			}
			if(hasLot2==true){
				parkingLot2.averageFee();
			}
			if(hasLot3==true){
				parkingLot3.averageFee();
			}
		}
		int main();
		void runMenu();
};
void SystemInterface::runMenu(){
	int choice;
	do {
		cout << "\n===== QUAN LY BAI DO XE =====\n";
		cout << "1. Tao Bai do xe moi\n";
		cout << "2. Them xe vao bai do\n";
		cout << "3. Xoa mot Bai do xe\n";
		cout << "4. Lay xe ra khoi bai do\n";
		cout << "5. Hien thi danh sach tat ca cac Bai do xe\n";
		cout << "6. Hien thi danh sach xe theo bai cu the\n";
		cout << "7. Liet ke xe theo loai phuong tien\n";
		cout << "8. Xem bao cao tom tat phi do xe trung binh\n";
		cout << "9. Thoat\n";
		cout << "Nhap lua chon cua ban (1-9): ";
		cin >> choice;

		switch(choice) {
			case 1: {
				int parkID; char size;
				cout << "Nhap parkID va size ('S', 'M', 'L'): ";
				cin >> parkID >> size;
				if(addLot(parkID, size)) 
					cout << "Tao bai xe thanh cong!\n";
				break;
			}
			case 2: {
				int vehicleID, entryTime, parkingDuration;
				string vehicleType;
				cout << "Nhap vehicleID, vehicleType (Car/Motorcycle/Bicycle), entryTime, parkingDuration: \n";
				cin >> vehicleID >> vehicleType >> entryTime >> parkingDuration;
				Vehicle newVehicle(vehicleID, vehicleType, entryTime, parkingDuration);
				newVehicle.calculateFee();
				bool added = false;
				if(parkingLot1.addVehicle(newVehicle)) 
					added = true;
				else if(parkingLot2.addVehicle(newVehicle)) 
					added = true;
				else if(parkingLot3.addVehicle(newVehicle)) 
					added = true;
				if(added) cout << "Them xe vao bai thanh cong!\n";
				else cout << "Khong the them xe (Bai day hoac khong du cho)!\n";
				break;
			}
			case 3: {
				int parkID;
				cout << "Nhap parkID can xoa: ";
				cin >> parkID;
				if(removeLot(parkID)) 
					cout << "Xoa bai xe thanh cong!\n";
				else cout << "Khong tim thay bai xe!\n";
				break;
			}
			case 4: {
				int vehicleID;
				cout << "Nhap vehicleID can lay ra: ";
				cin >> vehicleID;
				
				bool removed = false;
				if(parkingLot1.removeVehicle(vehicleID)) 
					removed = true;
				else if(parkingLot2.removeVehicle(vehicleID)) 
					removed = true;
				else if(parkingLot3.removeVehicle(vehicleID)) 
					removed = true;

				if(removed) 
					cout << "Lay xe ra khoi bai thanh cong!\n";
				else cout << "Khong tim thay xe!\n";
				break;
			}
			case 5: {
				if(hasLot1) 
					parkingLot1.displayLotInfor();
				if(hasLot2) 
					parkingLot2.displayLotInfor();
				if(hasLot3) 
					parkingLot3.displayLotInfor();
				break;
			}
			case 6: {
				int parkID;
				cout << "Nhap parkID can xem chi tiet: ";
				cin >> parkID;
				informationVehicle(parkID);
				break;
			}
			case 7: {
				string vehicleType;
				cout << "Nhap loai xe can tim: ";
				cin >> vehicleType;
				listVehicletype(vehicleType);
				break;
			}
			case 8:
				AverageFee();
				break;
			case 9:
				cout << "Thoat chuong trinh.\n";
				break;
			default:
				cout << "Lua chon khong hop le. Vui long chon lai!\n";
		}
	} while(choice != 9);
};
int main(){
	SystemInterface sys;
	sys.runMenu();
	return 0;
}		 
