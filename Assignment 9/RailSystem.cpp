//Dikshya Kafle 2018380039
#include "RailSystem.h"

void RailSystem::reset( void )
{
    /* Traverse the cities and initialize the city information */
    map<string, City*>::iterator it;
    for ( it = cities.begin(); it != cities.end(); ++it )
    {
        it->second->visited     = false;        /* Initially not accessed */
        it->second->total_fee       = INT_MAX;      /* The initial value is the maximum */
        it->second->total_distance  = INT_MAX;      /* The initial value is the maximum */
        it->second->from_city       = "";
    }
}


RailSystem::RailSystem( string const &filename )
{
    /* Call load_services to read */
    load_services( filename );
}


void RailSystem::load_services( string const &filename )
{
    /* If the file is normal, it will be read in the departure place, destination, cost, distance */
    ifstream    inf( filename.c_str() );
    string      from, to;
    int     fee, distance;

    while ( inf.good() )
    {
        /* If there is no departure city in the list, join */
        inf >> from >> to >> fee >> distance;

        if ( inf.good() )
        {
            Service* s = new Service( to, fee, distance );
            /* If there is no departure city in the list, join */
            
            if ( cities.count( from ) == 0 )
            {
                cities[from]        = new City( from );
                outgoing_services[from] = list<Service*>();
            }
            /* If there is no destination city in the list, join */
            if ( cities.count( to ) == 0 )
            {
                cities[to]      = new City( to );
                outgoing_services[to]   = list<Service*>();
            }
            outgoing_services[from].push_back( s ); /* Add data to the end of the city chain directly connected to the city of departure */
         }
        }
    }
    inf.close();
}


RailSystem::~RailSystem( void )
{
    /* destructor, freeing pointers in City map and Service map */
    map<string, City*>::iterator city_it = cities.begin();
    for (; city_it != cities.end(); city_it++ )
    {
        delete city_it->second;
    }
    map<string, list<Service*> >::iterator services_it =
        outgoing_services.begin();
    for (; services_it != outgoing_services.end(); services_it++ )
    {
        list<Service*>::iterator service_it = services_it->second.begin();
        for (; service_it != services_it->second.end(); service_it++ )
        {
            delete *service_it;
        }
    }
}


void RailSystem::output_cheapest_route( const string & from,
                    const string & to, ostream & out )
{
    /* Output the shortest path, call calc_route to calculate the shortest path */
    reset();
    pair<int, int> totals = calc_route( from, to );

    if ( totals.first == INT_MAX ) /* The fee is still the maximum description cannot be reached */
    {
        out << "There is no route from " << from << " to " << to << "\n";
    } else {
        out << "The cheapest route from " << from << " to " << to << "\n";
        out << "costs " << totals.first << " euros and spans " << totals.second
            << " kilometers\n";
        cout << recover_route( to ) << "\n\n";
    }
}


bool RailSystem::is_valid_city( const string & name )
{
    /* Determine if there is a bool function in the city */
    return(cities.count( name ) == 1);
}


pair<int, int> RailSystem::calc_route( string from, string to )
{
    /* Priority queue gets the minimum cost of the next city */
    priority_queue<City*, vector<City*>, Cheapest> candidates;
    
    /* Dijkstra shortest path algorithm: */
     /* Initialize the queue into the queue */
    City* start_city = cities[from];
    start_city->total_fee       = 0;
    start_city->total_distance  = 0;
    candidates.push( start_city ); /* Join the departure city at the end of the queue */
     /* When the priority queue is not empty */

    while ( !candidates.empty() )
    {
        /* City to visit */
        City* visiting_city;
         /* Set the head city to the city you want to visit */
        visiting_city = candidates.top();
        candidates.pop();  /* Top City Departure */
        
        /* If you have not visited this city */
        if ( !visiting_city->visited )
        {
            visiting_city->visited = true;/* Set to have been accessed */
             /* Traverse the city directly connected to the city */
            
            list<Service*>::iterator it;
            for ( it = outgoing_services[visiting_city->name].begin(); it != outgoing_services[visiting_city->name].end(); ++it )
            {
                /* Set the destination to the next city */
                City    * next_city = cities[(*it)->destination];
                int next_fee    = (*it)->fee + visiting_city->total_fee;
                /* Replace the new cost value when it is smaller than the old one */
                if ( (next_fee < next_city->total_fee) && next_city->name != from )
                {
                    next_city->total_fee        = next_fee;
                    next_city->total_distance   =
                        (*it)->distance + visiting_city->total_distance;
                    next_city->from_city = visiting_city->name;
                    candidates.push( next_city );
                }
            }
        }
    }
    /* Returns the total cost and total distance, otherwise returns the maximum value */
    if ( cities[to]->visited )
    {
        return(pair<int, int>( cities[to]->total_fee, cities[to]->total_distance ) );
    } else {
        return(pair<int, int>( INT_MAX, INT_MAX ) );
    }
}


string RailSystem::recover_route( const string & city )
{
   /* Use the stack to save the city name in the least cost route to return the city string in the positive order */
    string  route;
    string  current = city;
    while ( current != "" )
    {
        route = current + route;
        string prev = cities[current]->from_city;
        if ( prev != "" )
        {
            route = " to " + route;
        }
        current = prev;
    }
    return(route);
}
