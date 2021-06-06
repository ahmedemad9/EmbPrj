#define pi 3.141592		
#include <Math.h>
double lat1 , lon1 , lat2 , lon2 , a , c , d;

double deg2rad(double deg){
	double rad = deg*(pi/180);
	return rad;
}

double CalcGPSDistance(double lat1, double lon1, double lat2, double lon2){
		int R = 6371; // Radius of the earth in km										
  // distance between latitudes and longitudes
    double Lat = deg2rad(lat2 - lat1);
    double Lon = deg2rad(lon2 - lon1);
  
		double a = (sin( Lat / 2) * sin(Lat / 2)) + (
             cos(deg2rad(lat1)) * cos(deg2rad(lat2)))
						 *(sin(Lon/2) * sin(Lon/2));						 
		double  c = 2 * atan2(sqrt(a), sqrt(1-a)); 
		double  d = R * c; // Distance in km
		return d;
}
