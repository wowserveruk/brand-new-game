#pragma once
#include <unordered_map>
#include <string>
class Inventory{public:int capacity=30;std::unordered_map<std::string,int> items;int Count()const{int t=0;for(auto&i:items)t+=i.second;return t;}bool Add(const std::string&n,int q){if(Count()+q>capacity)return false;items[n]+=q;return true;}bool Remove(const std::string&n,int q){if(items[n]<q)return false;items[n]-=q;if(items[n]==0)items.erase(n);return true;}};
