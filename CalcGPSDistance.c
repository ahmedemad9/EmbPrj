#define pi 3.141592		
#include <Math.h>
float lat1 , lon1 , lat2 , lon2 , a , c , d;

float deg2rad(float deg){
	float rad = deg*(pi/180);
	return rad;
}

float CalcGPSDistance(float lat1, float lon1, float lat2, float lon2){
		int R = 6371; // Radius of the earth in km										
  // distance between latitudes and longitudes
    float Lat = deg2rad(lat2 - lat1);
    float Lon = deg2rad(lon2 - lon1);
  
		float a = (sin( Lat / 2) * sin(Lat / 2)) + (
             cos(deg2rad(lat1)) * cos(deg2rad(lat2)))
						 *(sin(Lon/2) * sin(Lon/2));						 
		float  c = 2 * atan2(sqrt(a), sqrt(1-a)); 
		float  d = R * c; // Distance in km
		return d;
}
