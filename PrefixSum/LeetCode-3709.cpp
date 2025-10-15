class ExamTracker {
public:
    vector<pair<int,long long>>prefix;
    long long score_ = 0;

    int binarySearch(int lo,int hi,int time){
        while(lo<hi){
            int mid = lo + (hi - lo)/2;
            if(prefix[mid].first<=time) lo = mid + 1;
            else hi = mid;
        }
        return lo-1;
    }

    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        score_ += score;
        prefix.push_back({time,score_});
    }
    
    long long totalScore(int startTime, int endTime) {
        int index1 = binarySearch(0,prefix.size(),startTime-1);
        int index2 = binarySearch(0,prefix.size(),endTime);
        if(index2<0) return 0;
        return prefix[index2].second-(index1>=0?prefix[index1].second:0);
    }
};