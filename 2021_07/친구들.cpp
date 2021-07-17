/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

//#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int Answer, N=0;
vector<int> v[100000];
bool visited[100000];

int DFS(int x){
    visited[x] = true;

    for(int i=0; i<v[x].size(); i++){
        if(visited[v[x][i]]) continue;
        DFS(v[x][i]);
    }

    return 1;
}

int main(int argc, char** argv)
{
	int T, test_case;

	//freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{


        for(int i=0; i<N; i++){
            v[i].clear();
            visited[i]=false;
        }

		Answer = 0;
		
        cin >> N;
        for(int i=0; i<N; i++){
            int a;
            cin >> a;

            if(a+i >= N) continue;
            v[i].push_back(a+i);
            v[a+i].push_back(i);
        }

        for(int i=0; i<N; i++)
            if(!visited[i])
                Answer += DFS(i);
        
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

/*
1 2  3 4 5 6 7 8 9 10
8 10 5 4 2 5 1 3 1 9

1 9 10
2
3 4 5 7 8
6 


*/