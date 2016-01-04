#include "Matrix.h"

/********HeaderItem********/


void HeaderItem::print(){
    cout<<"{_id: "<<_id<<", _group:"<<_group<<", _value:"<<_value<<"}"<<endl;
}

HeaderItem::HeaderItem(size_t id, string value){
    _id = id;
    _value = value;
    _group = -1;
}

void HeaderItem::setData(size_t id, string value, size_t group){
    _id = id;
    _value = value;
    _group = group;
}



/********Matrix********/


void Matrix::print(){
    cout<<"{"<<endl;
    cout<<"y:"<<endl;
    for(int i=0;i!=y.size();i++){
        cout<<"    ";
        y[i].print();
    }
    cout<<"m:"<<endl;
    for(int i=0;i!=y.size();i++){
        cout<<"    (";
        for(int j=0;j!=D;j++){
            cout<<m[i][j]<<", ";
        }
        cout<<")"<<endl;
    }
    cout<<"}"<<endl;
}

map<intptr_t, size_t> & Matrix::getIdMap(){

    if(idMap.empty()){
        setIdMap();
    }
    return idMap;
};

void Matrix::setIdMap(){
    if(!idMap.empty()){
        return;
    }
    for(size_t i=0;i!=m.size();i++){
        idMap[(intptr_t)(m[i])] = y[i]._id;
    }
    return;
}

void Matrix::updateGroup(map<size_t, vector<double*>> kPoints){

    setIdMap();
    for(auto i : kPoints){
        for(size_t j=1;j!=i.second.size();j++){
            size_t tid = idMap[(intptr_t)i.second[j]];
            y[tid]._group = i.first;
        }
    }
}
