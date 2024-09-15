#include <bits/stdc++.h>

using namespace std;


void print(vector< vector< vector<int> > > &arr3d){
    for(int i = 0; i < arr3d.size(); i++){
        for(int j = 0; j < arr3d[i].size(); j++){
            for(int k = 0; k < arr3d[i][j].size(); k++){
                cout<<arr3d[i][j][k]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    vector< vector< vector< int> > > arr3d;
    int r, c, h;
    cout<<"How many 2D vectors you want to create?"<<endl;
    cin>>h;

    for(int i = 0; i<h; i++){
        cout<<"Enter number of rows and columns for "<<i+1<<" 2D vector"<<endl;
        cin>>r>>c;
        cout<<endl<<"Enter "<<r*c<<" numbers of element :"<<endl;
        vector< vector<int> > vec2d(r, vector<int>(c));
        for(int j = 0; j < r; j++){
            for(int k = 0; k < c; k++){
                cin >> vec2d[j][k];
            }
        }

        arr3d.push_back(vec2d);
    }

    cout<<endl<<"Display"<<endl;
    print(arr3d);
    return 0;

}