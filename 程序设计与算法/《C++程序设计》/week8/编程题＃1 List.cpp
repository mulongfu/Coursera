#include <iostream> 
#include <list>
#include <string>
#include <map>
using namespace std;

map <int, list<int> > idtolist;

int main() { 
    int n = 0, id, id2, num;
    string order;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> order;
    	if(order == "new"){
			cin >> id;
			idtolist[id];
			/*map<int, list<int> >::iterator i = idtolist.begin();
			cout << i->first;
			i++;
			cout << i->first;*/
    	}
    	else if(order == "add"){
    		cin >> id >> num;
    		idtolist.find(id)->second.push_front(num);
    	}
    	else if(order == "out"){
    		cin >> id;
    		idtolist.find(id)->second.sort();
    		list<int>::iterator i = idtolist.find(id)->second.begin();
    		for(i; i!=idtolist.find(id)->second.end(); i++)
    		cout << *i << " ";
    		cout << endl;
    	}
    	else if(order == "merge"){
    		cin >> id >> id2;
    		list<int>::iterator i2 = idtolist.find(id)->second.end();
    		idtolist.find(id)->second.splice(i2, idtolist.find(id2)->second);
    	}
    	else if(order == "unique"){
    		cin >> id;
    		idtolist.find(id)->second.sort();
    		idtolist.find(id)->second.unique();
    	}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
