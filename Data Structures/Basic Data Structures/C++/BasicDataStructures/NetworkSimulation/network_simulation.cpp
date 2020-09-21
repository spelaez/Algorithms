//
//  main.cpp
//  NetworkSimulation
//
//  Created by Santiago Pelaez Rua on 20/09/20.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Request {
    Request(int arrival_time, int process_time):
    arrival_time(arrival_time),
    process_time(process_time)
    {}
    
    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
    dropped(dropped),
    start_time(start_time)
    {}
    
    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size):
    size_(size),
    finish_time_()
    {}
    
    Response Process(const Request &request) {
        currentTime = request.arrival_time;
        
        while(!finish_time_.empty() && finish_time_.front() <= currentTime) {
            finish_time_.pop();
        }
        
        if(finish_time_.size() == size_) {
            //buffer full
            return Response(true, -1);
        }
        
        if(finish_time_.empty()) {
            finish_time_.push(currentTime + request.process_time);
            return Response(false, currentTime);
        } else {
            int finishTimeBack = finish_time_.back();
            finish_time_.push(finishTimeBack + request.process_time);
            return Response(false, finishTimeBack);
        }
    }
    
private:
    int size_;
    int currentTime = 0;
    queue<int> finish_time_;
};

vector <Request> ReadRequests() {
    vector<Request> requests;
    int count;
    cin >> count;
    for(int i = 0; i < count; i++) {
        int arrival_time, process_time;
        cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    
    return requests;
}

vector <Response> ProcessRequests(const vector<Request> &requests, Buffer *buffer) {
    vector<Response> responses;
    for(int i = 0; i < requests.size(); i++)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void PrintResponses(const vector <Response> &responses) {
    for(int i = 0; i < responses.size(); i++)
        cout << (responses[i].dropped ? -1 : responses[i].start_time) << endl;
}

int main(int argc, const char * argv[]) {
    int size;
    cin >> size;
    vector<Request> requests = ReadRequests();
    
    Buffer buffer(size);
    vector<Response> responses = ProcessRequests(requests, &buffer);
    
    PrintResponses(responses);
    return 0;
}
