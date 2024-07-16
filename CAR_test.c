#include <stdio.h>
char start_options;
int engine_state=0;
char sensors_set_menu;
char traffic_light;
int room_temperature=30;
int engine_temperature=90;
int AC_sensor=0;
int Engine_controller=0;
int vehicle_speed=0;
void starting_options(void);
int start_menu(void);
int sensors_settings(void);
int temperature(void);
int engine_controller(void);
int set_traffic_light(void);
void speed(char traffic_light);
void state(void);







int main(void){
	printf("Hello \n");
	starting_options();
	return 0;
}





void starting_options(void) {
	while (1) {
		printf("Good morning, wishing you a pleasing day. What do you want to do right now? \n");
		printf("a. Turn on the vehicle engine \n");
		printf("b. Turn off the vehicle engine \n");
		printf("c. Quit the system \n");

		scanf(" %c", &start_options);

		if (start_options == 'a') {
			engine_state = 1;
			printf("The engine is turned ON \n");
			sensors_settings();
		}
		else if (start_options == 'b') {
			printf("The vehicle engine is turned off \n");
			engine_state = 0;
			starting_options();
		}
		else if (start_options == 'c') {
			printf("The system is quitting now \n");
			break; // Exit the while loop
		}
		else {
			printf("Please enter a valid character \n");
		}
	}
	return;
}






int sensors_settings(void){
	printf("please choose from the sensors set menu: \n");
	printf("a. Turn off the engine \n b. Set the traffic light color. \n c. Set the room temperature  \n d. Set the engine temperature \n");
	scanf(" %c",&sensors_set_menu);
	if(sensors_set_menu=='a'){
		engine_state=0;
		printf("The vehicle engine is turned off \n");
		starting_options();
	}
	else if(sensors_set_menu=='b')
		set_traffic_light();
	else if(sensors_set_menu=='c')
		temperature();
	else if(sensors_set_menu=='d')
		engine_controller();
return 0;
}
void state(void){

	if(engine_state)
		printf("Engine is ON \n");
	else
		printf("Engine is OFF \n");

        if(AC_sensor)
		printf("AC is ON \n");
	else
		printf("AC is OFF \n");

	if(Engine_controller)
		printf("Engine temperature controller is ON \n ");
	else
		printf("Engine temperature controller is OFF \n");
	printf("The room temperature is: %d", room_temperature);
	printf("\n The engine temperature is: %d", engine_temperature);
	printf("\n The vehicle speed is: %d \n", vehicle_speed);
	sensors_settings();
}

int temperature(void){
	if ( (!AC_sensor) && (vehicle_speed==30)){
		printf("the AC is off, please enter the Current room temperature to turn it on: \n");
		scanf("%d",&room_temperature);
        AC_sensor=1;
		room_temperature = (float)room_temperature*5/4+1;
		printf("\n the AC temperature is set to: %d \n",room_temperature);
		engine_controller();
	}
	else {
		printf("please enter the room temperature : \n ");
		scanf(" %d",&room_temperature);
		if((room_temperature <10) || (room_temperature >30)){
			printf("The AC is ON and room temperature is to be 20 \n");
			AC_sensor=1;
			room_temperature=20;
			if (traffic_light =='O')
            engine_controller();
			state();
		}
		else {
			printf("The AC is OFF \n");
			state();
		}
	}


	return 0;
}
int engine_controller(void){
	if( (! Engine_controller)&&(vehicle_speed==30)){
			printf("the Engine temperature controller is off, please enter the Current engine temperature to turn it on: \n");
			scanf("%d",&engine_temperature);
	        Engine_controller=1;
			engine_temperature = (float)engine_temperature*5/4+1;
			printf("\n the engine temperature is : %d \n",engine_temperature);
			state();

		}
	else{
		printf("please enter the engine temperature : \n ");
		scanf(" %d",&engine_temperature);
		if((engine_temperature <100) || (engine_temperature >150)){
			printf("The Engine Temperature Controller is ON and and temperature is to be 125 \n");
			Engine_controller=1;
			engine_temperature=125;
			state();
		}
		else{
			printf("The Engine Temperature Controller is OFF \n");
			state();
		}
	}

return 0;
}


void speed(char traffic_light){
	switch(traffic_light){
	case 'G':
	{
		printf("the vehicle speed is set to 100 km/hr \n");
		vehicle_speed=100;
		break;
	}
	case 'O':
	{
		printf("the vehicle speed is set to 30 km/hr \n");
		vehicle_speed=30;
		temperature();
		break;
	}
	case 'R':{
		printf("the vehicle speed is set to 0 km/hr \n");
		vehicle_speed=0;
		break;
	}
	}
	state();
}

int set_traffic_light(void){

	printf("What is the traffic light color \n G.Green \n O.Orange \n R.Red: \n ");
	scanf(" %c",&traffic_light);
	if(traffic_light == 'G')
	{
		speed(traffic_light);
	}
	if(traffic_light == 'O')
	{
		speed(traffic_light);

	}
	if(traffic_light == 'R')
		speed(traffic_light);
	return 0;
}
