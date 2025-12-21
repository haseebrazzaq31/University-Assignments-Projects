#include <iostream>
using namespace std;
void displaySeats(int bus[10][10]){
    cout<<"    Current Bus Seating   "<<endl;
    cout<<"   0 1 2 3 4 5 6 7 8 9"<<endl;
    for(int i = 0; i < 10; i++){
        cout<<i<<"  ";
        for(int j = 0; j < 10; j++){
            cout<<bus[i][j]<<" ";
        }
        cout<<endl;
    }
}
void reserveSeat(int bus[10][10]){
    int r, c;
    cout<<"Enter row number (0-9): ";
    cin>>r;
    cout<<"Enter column number (0-9): ";
    cin>>c;
    if(bus[r][c] == 0){
        bus[r][c] = 1;
        cout<<" Seat reserved"<<endl;
    }else{
        cout<<" Seat already taken"<<endl;
    }
}
void cancelSeat(int bus[10][10]){
    int r, c;
    cout<<"Enter row number (0-9): ";
    cin>> r;
    cout<<"Enter column number (0-9): ";
    cin>>c;
    if(bus[r][c] == 1){
        bus[r][c] = 0;
        cout<<" Reservation cancelled"<<endl;
    }else{
        cout<<" Seat was already empty"<<endl;
    }
}
void checkStatus(int bus[10][10]){
    int totalOccupied = 0;
    int fullRows = 0;
    int emptyRows = 0;
    int partialRows = 0;
    for(int i = 0; i < 10; i++){
        int rowCount = 0;
        for(int j = 0; j < 10; j++){
            if(bus[i][j] == 1){
                rowCount++;
                totalOccupied++;
            }
        }
        if(rowCount == 10){
            fullRows++;
        }else if(rowCount == 0){
            emptyRows++;
        }else{
            partialRows++;
        }
    }
    cout<<"\n--- Seating Statistics ---" <<endl;
    cout<<"Total Seats Occupied: "<<totalOccupied <<endl;
    cout<<"Fully Occupied Rows: "<< fullRows<<endl;
    cout<<"Partially Occupied Rows: "<<partialRows<<endl;
    cout<<"Empty Rows: "<<emptyRows<<endl;
}
int main() {
    int busSeats[10][10] = {0};
    int choice = 0;
    while(choice != 5){
        cout<<"BUS RESERVATION MENU"<<endl;
        cout<<"1. Display Seats map "<<endl;
        cout<<"2. Reserve Seat"<<endl;
        cout<<"3. Cancel Seat"<<endl;
        cout<<"4. View Seating Summary"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                displaySeats(busSeats);
                break;
            case 2:
                reserveSeat(busSeats);
                break;
            case 3:
                cancelSeat(busSeats);
                break;
            case 4:
                checkStatus(busSeats);
                break;
            case 5:
                cout<<"Exiting Booking system"<<endl;
                break;
            default:
                cout<<"Invalid choice, "<<endl;
        }
    }
    return 0;
}