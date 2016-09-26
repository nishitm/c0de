//Problem: Suppose you have some guests arriving at a party.
        // For each guest, you are given the arrival and departure time.
        // When a guest arrives he is given a wine glass and when he leaves he returns that wine glass (it becomes available to be given to another guest).
        // Find the minimum number of wine glasses needed to serve all the guests.
        // The arrival and departure team can only be between 1800 to 2359 hours.

#include<bits/stdc++.h>
using namespace std;

int MinGlasses(vector<int> guest_arrival, vector<int> guest_departure, int n)
{
  int arrivals[600], departures[600];

  for (int i=0; i<600; i++)
  {    arrivals[i] = 0;
      departures[i] = 0;
  }

  for(int i=0; i<n; i++)
  {
    arrivals[guest_arrival[i] - 1800]++;
    departures[guest_departure[i] - 1800]++;
  }
  int res = 0, available_glasses = 0;
  for (int i=0; i<600; i++)
  {
      available_glasses += departures[i];
      if (arrivals[i] > available_glasses)
      {
          res += arrivals[i] - available_glasses;
          available_glasses = 0;
      }
      else
          available_glasses -= arrivals[i];
  }
  return res;
}


int main()
{
  vector<int> guest_arrival, guest_departure;
  int no_of_guest;

  cout<<"Enter no of guests:";
  cin>>no_of_guest;

  cout<<"\nEnter arrival and departure timings(between 1800-2359):";

  for(int i=0; i<no_of_guest; i++)
  {
    int t;
    cout<<"\nEnter arrival time:";
    cin>>t;
    guest_arrival.push_back(t);
    cout<<"\nEnter departure time:";
    cin>>t;
    guest_departure.push_back(t);
  }

  int no_of_wine_glasses = MinGlasses(guest_arrival,guest_departure,no_of_guest);

  cout<<"No of min wine glasses required:"<<no_of_wine_glasses<<endl;

  return 0;
}
