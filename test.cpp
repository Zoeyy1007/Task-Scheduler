#include <gtest/gtest.h>
#include "EventSearch.h"
#include "EventManager.h"
#include <iostream>
#include <sstream>

using namespace std;


TEST(EventManagerTests, AddEvent){
    EventManager* em = new EventManager();

    
    em->add_event("Project meeting", "2025-02-27", "Office", "Business");
    
  
    EXPECT_EQ(em->get_event_count(), 1);
}


TEST(EventManagerTests, DeleteEvent){
    EventManager* em = new EventManager();
    em->add_event("Project meeting", "2025-02-27", "Office", "Business");
    
    
    em->remove_event(0);
    EXPECT_EQ(em->get_event_count(), 0);
}

TEST(EventManagerTests, InvalidDeleteEvent){
    stringstream buffer;
    streambuf* Output = cout.rdbuf(buffer.rdbuf());  
    
    EventManager* em = new EventManager();
    em->remove_event(0);  
    
    cout.rdbuf(Output);  
    
    string output = buffer.str();
    EXPECT_EQ(output, "Event not found\n");
}

TEST(EventSearchTests, SearchEventByDate){
    EventManager* em = new EventManager();
    em->add_event("Project meeting", "2025-02-27", "Office", "Business");
    EventSearch* es = new EventSearch(em);

    
    vector<Event> results = es->search_by_date("2025-02-27");
    
    EXPECT_EQ(results.size(), 1);
}

TEST(EventSearchTests, SearchEventByType){
    EventManager* em = new EventManager();
    em->add_event("Project meeting", "2025-02-27", "Office", "Business");
    EventSearch* es = new EventSearch(em);
    
    vector<Event> results = es->search_by_type("Business");
    
    EXPECT_EQ(results.size(), 1);
}

TEST(EventSearchTests, InvalidSearchEvent){
    stringstream buffer;
    streambuf* Output = cout.rdbuf(buffer.rdbuf());  
    
    EventManager* em = new EventManager();
    EventSearch* es = new EventSearch(em);
    
    vector<Event> results = es->search_by_date("2025-03-01");
    
    cout.rdbuf(Output);  
    
    EXPECT_EQ(results.size(), 0);
    string output = buffer.str();
    EXPECT_EQ(output, "No events found for the given criteria\n");
}
