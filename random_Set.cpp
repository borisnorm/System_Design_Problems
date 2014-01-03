//Implement a RandomSet structure which supports insert, remove, random, search in O(1) operation
//Analysis:  O(1) search insert is array. we could use array+hashtable (hash_map)

class randomSet{
public:
  hash_map<int,int> m;//value->index map
  vector<int> array;
  
  void insert(int a){
    if( m.find(a)!=m.end() && m[a]>=0)
      return;
    array.push_back(a);
    m[a]=array.size()-1;
  }
  
  int search(int a){
    if(m.find(a)==m.end() || m[a]==-1)
      return -1;
    return m[a];  
  }
  
  void remove(int a){
    if(m.find(a)==m.end() || m[a]==-1)
      return;
    int index=m[a];
    array[index]=array.back();
    array.pop_back();
    m[a]=-1;
    m[array[index]]=index;
  }
};
