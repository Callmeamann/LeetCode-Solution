class MedianFinder {
private:
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
public:
    MedianFinder() {
        
    }
    void balance(int m , int n){
        if(m > n){
            min.push(max.top());
            max.pop();
            cout<<"going to min"<<endl;
        }
        else{
            max.push(min.top());
            min.pop();
            cout<<"going to max"<<endl;
        }
    }
    void addNum(int num) {
        if(max.empty())
            max.push(num);
        else if(min.empty()){
            if(num < max.top()){
                min.push(max.top());
                max.pop();
                max.push(num);
            }
            else
                min.push(num);
        }
        else{
            if(num <= max.top()) max.push(num);
            else min.push(num);
            int x = max.size() ,y=  min.size();
            if(abs(x-y) > 1 || y>x)
                balance(x,y);
        }
    }
    
    double findMedian() {
        int x = max.size() , y= min.size();
        if((x+y)%2 ==0){
            return ((max.top() + min.top())/2.0);
        }
        return max.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */