#include <iostream>
#include <math.h>

using namespace std;

void Triplet1(int a[3], int b[3]) {
	int result[]={0,0};

	if(a[0]<b[0]){
		result[1]+=1;
	}
	if(a[0]>b[0]){
		result[0]+=1;
	}
	if(a[1]<b[1]){
		result[1]+=1;
	}
	if(a[1]>b[1]){
		result[0]+=1;
	}
	if(a[2]<b[2]){
		result[1]+=1;
	}
	if(a[2]>b[2]){
		result[0]+=1;
	}
	cout<<"Triplet1: "<<result[0]<<","<<result[1]<<endl;
}

void Triplet2(int a[3], int b[3]) { //Esta version de el codigo de tripletas es mas eficiente
	int result[]={0,0};				//ya que toma muchas menos lineas de iteracion y en lugar de hacer demasiadas
									//comparaciones, hace solo las necesarias dentro de un for
	for(int i=0; i<3; i++){
		if(a[i]<b[i]){
			result[1]+=1;
		}
		if(a[i]>b[i]){
			result[0]+=1;
		}
	}
	cout<<"Triplet2: "<<result[0]<<","<<result[1]<<endl;
}

void Time1(string time) {
	string result = time.substr(2, 6);
	int hours = std::stoi(time.substr(0,2));

	if(time[8]=='A' && hours==12)
		hours = 0;
	if(time[8]=='P'){
		hours += 12;
	}
	
	if(hours<10)
		cout<<"Time1: "<<"0"+to_string(hours)+result<<endl;
	else{
		cout<<"Time1: "<<std::to_string(hours)+result<<endl;
	}
}

void Time2(string time) {				//En esta funcion se usa un valor
	string result = time.substr(2, 6);	//de conversion para aplicarle a las horas
	int hours = stoi(time.substr(0,2)); //y asi hacer menos comparaciones
	int convert = (hours%12)/hours;

	if(time[8]=='A')
		convert--;
		
	hours += (12*convert);
	
	if(hours<10)
		cout<<"Time2: "<<"0"+to_string(hours)+result<<endl;
	else{
		cout<<"Time2: "<<to_string(hours)+result<<endl;
	}
}

void Minion(string word){
    int score[2]={0,0};
    for(int i=0;i<word.length();i++){
        if(word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U')
        	score[1]+=word.length()-i;
        else{
        	score[0]+=word.length()-i;
		}               
    }
    if(score[1]>score[0])
        cout<<"Minion: Kevin "<<score[1]<<endl;
    else if(score[1]<score[0]){
        cout<<"Minion: Stuart "<<score[0]<<endl;
    }
    else{
        cout<<"Minion: Empate"<<endl;
    }
}

void Pairs(int values[2] , int nums[]){
	int result=0;
	for(int i=0;i<values[0];i++){
		for(int k=i;k<values[0];k++){
			if(abs(nums[i]-nums[k])==values[1])
				result++;
		}
	}
	cout<<"Pairs: "<<result<<endl;
}

int main(){

	int Trip1[]={1,2,3};
    int Trip2[]={3,2,4};
    int Trip3[]={2,3,4};
    int Trip4[]={1,2,4};
	int val1[]={5,2};
	int val2[]={7,3};
	int num1[]={5,3,2,4,1};
	int num2[]={7,3,9,1,5,8,2};

	Triplet1(Trip1, Trip2);
	Triplet1(Trip3, Trip4);
	cout<<endl<<"////////////////////////"<<endl<<endl;
	Triplet2(Trip1, Trip2);
	Triplet2(Trip3, Trip4);
	cout<<endl<<"////////////////////////"<<endl<<endl;
	Time1("12:43:09AM");
	Time1("03:21:56PM");
	cout<<endl<<"////////////////////////"<<endl<<endl;
	Time2("12:43:09PM");
	Time2("03:21:56AM");
	cout<<endl<<"////////////////////////"<<endl<<endl;
	Minion("GHOST");
	Minion("GLAIVE");
	cout<<endl<<"////////////////////////"<<endl<<endl;
	Pairs(val1,num1);
	Pairs(val2,num2);

	return 0;
}