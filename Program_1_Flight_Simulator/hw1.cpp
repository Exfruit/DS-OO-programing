/*input
1000
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <ctime>
#include <cstdlib>
using namespace std;

const int total_runway = 4;

struct plane
{
	int id;
	int fuel;
	int waiting_time;
}temp;
struct runway
{
	vector<plane> L1;
	vector<plane> L2;
	vector<plane> T;
}runway[total_runway];
bool comp(plane l, plane r){
	if(l.id < r.id)
		return true;
	else 
		return false;
}

int main(){
	srand(time(NULL));
	cout << "How many time unit you want to simulate?" << '\n';
	int time;	cin >> time;
	int plane_to_land, plane_to_takeoff, land_num = 1, takeoff_num = 0, 
			plane_in_runway[total_runway], min, min_num, plane_crashed = 0, 
				landing_waiting_time = 0, takeoff_waiting_time = 0, waiting_fucking_long, 
					fucking_waiting_time = 0, who_wait_fucking_long, fuel_save = 0, emergency_plane = 0, 
						landing_succeed = 0;
	for(int i = 0; i < time; i++){
		if(i < 5){
			cout << "Time = " << i + 1 << '\n';
		}
		//STEP 1!!!!!!!!!!!!!!!
		plane_to_land = rand() % 4;
		// cout << plane_to_land << '\n';
		if(i < 5){
			cout << "Step 1 : " << '\n';
			cout << "landing plane : ";
		}
		for(int j = 0; j < plane_to_land; j++){
			temp.id = land_num;
			land_num += 2;
			temp.fuel = rand() % 10 + 1;
			temp.waiting_time = 0;
			plane_in_runway[1] = runway[1].L1.size() + runway[1].L2.size() + runway[1].T.size();
			plane_in_runway[2] = runway[2].L1.size() + runway[2].L2.size() + runway[2].T.size();
			plane_in_runway[3] = runway[3].L1.size() + runway[3].L2.size() + runway[3].T.size();
			min = 1000;
			min_num = 1;
			for(int k = 1; k <= 3; k++){
				if(plane_in_runway[k] < min){
					min = plane_in_runway[k];
					min_num = k;
				}
			}
			if(runway[min_num].L1.size() <= runway[min_num].L2.size()){
				runway[min_num].L1.push_back(temp);
			}
			else
				runway[min_num].L2.push_back(temp);
			if(i < 5)
				cout << "(" << temp.id << ", " << temp.fuel << "), ";
		}
		if(i < 5){
			cout << '\n' << '\n';
			for(int j = 0; j < 4; j++){
				cout << "Runway" << j + 1 << "(-1)" << '\n';
				cout << "L1 : ";
				for(int k = 0; k < runway[j].L1.size(); k++){
					cout << "(" << runway[j].L1[k].id << ", " << runway[j].L1[k].fuel << "), ";
				}
				cout << '\n' << "L2 : ";
				for(int k = 0; k < runway[j].L2.size(); k++){
					cout << "(" << runway[j].L2[k].id << ", " << runway[j].L2[k].fuel << "), ";
				}
				cout << '\n' << "T : ";
				for(int k = 0; k < runway[j].T.size(); k++){
					cout << "(" << runway[j].T[k].id << ", " << runway[j].T[k].fuel << "), ";
				}
				cout << '\n' << '\n';
			}
		}
		// STEP 2!!!!!!!!!!!!!!!!!
		plane_to_takeoff = rand() % 4;
		if(i < 5){
			cout << "Step 2 : " << '\n';
			cout << "takeoff plane : ";
		}
		for(int j = 0; j < plane_to_takeoff; j++){
			temp.id = takeoff_num;
			takeoff_num += 2;
			temp.fuel = 100;
			temp.waiting_time = 0;
			plane_in_runway[0] = runway[0].T.size();
			plane_in_runway[1] = runway[1].L1.size() + runway[1].L2.size() + runway[1].T.size();
			plane_in_runway[2] = runway[2].L1.size() + runway[2].L2.size() + runway[2].T.size();
			plane_in_runway[3] = runway[3].L1.size() + runway[3].L2.size() + runway[3].T.size();
			min = 1000;
			min_num = 0;
			for(int k = 0; k <= 3; k++){
				if(plane_in_runway[k] < min){
					min = plane_in_runway[k];
					min_num = k;
				}
			}
			runway[min_num].T.push_back(temp);
			if(i < 5)
				cout << "(" << temp.id << "), ";
		}
		if(i < 5){
			cout << '\n' << '\n';
			for(int j = 0; j < 4; j++){
				cout << "Runway" << j + 1 << "(-1)" << '\n';
				cout << "L1 : ";
				for(int k = 0; k < runway[j].L1.size(); k++){
					cout << "(" << runway[j].L1[k].id << ", " << runway[j].L1[k].fuel << "), ";
				}
				cout << '\n' << "L2 : ";
				for(int k = 0; k < runway[j].L2.size(); k++){
					cout << "(" << runway[j].L2[k].id << ", " << runway[j].L2[k].fuel << "), ";
				}
				cout << '\n' << "T : ";
				for(int k = 0; k < runway[j].T.size(); k++){
					cout << "(" << runway[j].T[k].id << "), ";
				}
				cout << '\n' << '\n';
			}
		}
		
		// STEP 3!!!!!!!!!!!!!
		vector<plane> emergency;
		emergency.clear();
		for(int j = 1; j < 4; j++){
			for(int k = 0; k < runway[j].L1.size(); k++){
				if(runway[j].L1[k].fuel == 1){
					emergency.push_back(runway[j].L1[k]);
				}
			}
			for(int k = 0; k < runway[j].L2.size(); k++){
				if(runway[j].L2[k].fuel == 1){
					emergency.push_back(runway[j].L2[k]);
				}
			}
		}
		sort(emergency.begin(), emergency.end(), comp);
		if(i < 5){
			cout << "Step 3 : " << '\n';
			cout << "emergency plane : ";
			for(int j = 0; j < emergency.size(); j++){
				cout << "(" << emergency[j].id << "), ";
			}
			cout << '\n' << '\n';
			for(int j = 0; j < 4; j++){
				cout << "Runway" << j + 1 << "(-1)" << '\n';
				cout << "L1 : ";
				for(int k = 0; k < runway[j].L1.size(); k++){
					cout << "(" << runway[j].L1[k].id << ", " << runway[j].L1[k].fuel << "), ";
				}
				cout << '\n' << "L2 : ";
				for(int k = 0; k < runway[j].L2.size(); k++){
					cout << "(" << runway[j].L2[k].id << ", " << runway[j].L2[k].fuel << "), ";
				}
				cout << '\n' << "T : ";
				for(int k = 0; k < runway[j].T.size(); k++){
					cout << "(" << runway[j].T[k].id << "), ";
				}
				cout << '\n' << '\n';
			}
		}

		
		// STEP 4!!!!!!!!!
		if(i < 5)
			cout << "Step 4 : " << '\n' << '\n';
		bool full = false;
		int on_runway[4];
		for(int j = 0; j < 4; j++){
			full = false;
			// ~~~check whether there is a emergency plane~~~
			for(int k = 0; k < runway[j].L1.size(); k++){
				if(runway[j].L1[k].fuel == 1){
					emergency_plane++;
					if(full == true){
						plane_crashed++;
						runway[j].L1.erase(runway[j].L1.begin() + k - 1);
					}
					else{
						on_runway[j] = runway[j].L1[k].id;
						full = true;
						landing_waiting_time += runway[j].L1[k].waiting_time;
						fuel_save += runway[j].L1[k].fuel;
						landing_succeed++;
						runway[j].L1.erase(runway[j].L1.begin() + k - 1);
					}
				}
			}
			for(int k = 0; k < runway[j].L2.size(); k++){
				if(runway[j].L2[k].fuel == 1){
					emergency_plane++;
					if(full == true){
						plane_crashed++;
						runway[j].L2.erase(runway[j].L2.begin() + k - 1);
					}
					else{
						on_runway[j] = runway[j].L2[k].id;
						full = true;
						landing_waiting_time += runway[j].L2[k].waiting_time;
						fuel_save += runway[j].L2[k].fuel;
						landing_succeed++;
						runway[j].L2.erase(runway[j].L2.begin() + k - 1);
					}
				}
			}
			// no emergency plane --> choose the longest waiting_time
			if(full == false){
				waiting_fucking_long = 0;	//which queue : 1 = L1, 2 = L2, 3 = T
				fucking_waiting_time = -1;
				for(int k = 0; k < runway[j].L1.size(); k++){
					if(runway[j].L1[k].waiting_time > fucking_waiting_time){
						who_wait_fucking_long = k;
						fucking_waiting_time = runway[j].L1[k].waiting_time;
						waiting_fucking_long = 1;
					}
				}
				for(int k = 0; k < runway[j].L2.size(); k++){
					if(runway[j].L2[k].waiting_time > fucking_waiting_time){
						who_wait_fucking_long = k;
						fucking_waiting_time = runway[j].L2[k].waiting_time;
						waiting_fucking_long = 2;
					}
				}
				for(int k = 0; k < runway[j].T.size(); k++){
					if(runway[j].T[k].waiting_time > fucking_waiting_time){
						who_wait_fucking_long = k;
						fucking_waiting_time = runway[j].T[k].waiting_time;
						waiting_fucking_long = 3;
					}
				}
				// put the plane into the runway
				if(full == false){
					if(waiting_fucking_long == 1){
						on_runway[j] = runway[j].L1[who_wait_fucking_long].id;
						full = true;
						landing_waiting_time += runway[j].L1[who_wait_fucking_long].waiting_time;
						fuel_save += runway[j].L1[who_wait_fucking_long].fuel;
						landing_succeed++;
						runway[j].L1.erase(runway[j].L1.begin() + who_wait_fucking_long - 1);
					}
					else if(waiting_fucking_long == 2){
						on_runway[j] = runway[j].L2[who_wait_fucking_long].id;
						full = true;
						landing_waiting_time += runway[j].L2[who_wait_fucking_long].waiting_time;
						fuel_save += runway[j].L1[who_wait_fucking_long].fuel;
						landing_succeed++;
						runway[j].L2.erase(runway[j].L2.begin() + who_wait_fucking_long - 1);
					}
					else if(waiting_fucking_long == 3){
						on_runway[j] = runway[j].T[who_wait_fucking_long].id;
						full = true;
						takeoff_waiting_time += runway[j].T[who_wait_fucking_long].waiting_time;
						runway[j].T.erase(runway[j].T.begin() + who_wait_fucking_long - 1);
					}
				}
			}
		}
		if(i < 5){
			for(int j = 0; j < 4; j++){
				cout << "Runway" << j + 1 << "(" << on_runway[j] << ")" << '\n';
				cout << "L1 : ";
				for(int k = 0; k < runway[j].L1.size(); k++){
					cout << "(" << runway[j].L1[k].id << ", " << runway[j].L1[k].fuel << "), ";
				}
				cout << '\n' << "L2 : ";
				for(int k = 0; k < runway[j].L2.size(); k++){
					cout << "(" << runway[j].L2[k].id << ", " << runway[j].L2[k].fuel << "), ";
				}
				cout << '\n' << "T : ";
				for(int k = 0; k < runway[j].T.size(); k++){
					cout << "(" << runway[j].T[k].id << "), ";
				}
				cout << '\n' << '\n';
			}
		}
		
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < runway[j].L1.size(); k++){
				runway[j].L1[k].waiting_time++;
				runway[j].L1[k].fuel--;
			}
			for(int k = 0; k < runway[j].L2.size(); k++){
				runway[j].L2[k].waiting_time++;
				runway[j].L2[k].fuel--;
			}
			for(int k = 0; k < runway[j].T.size(); k++){
				runway[j].T[k].waiting_time++;
			}
		}
	}
	cout << "How many time unit you want to simulate : " << time << '\n';
	cout << "average landing waiting time : " << (double(landing_waiting_time) / (land_num / 2 + 1)) << "(s)" << '\n';
	cout << "average takeoff waiting time : " << (double(takeoff_waiting_time) / (takeoff_num / 2 + 1)) << "(s)" << '\n';
	cout << "average fuel saved : " << (double(fuel_save) / landing_succeed) << "(ml)" << '\n';
	cout << "total plane in emergency : " << emergency_plane << '\n';
	cout << "total plane crashed : " << plane_crashed << '\n';

	return 0;
	
}