#ifndef PRARX_H_
#define PRARX_H_
#pragma once

#include <platoon.h>

template<int NCAR>
class Prarx : public DriverModel<NCAR>{
public:
    //using model_t = typename Model<3*NCAR, 1*NCAR>;
    using x_t = typename Model<3*NCAR, 1*NCAR>::x_t;
    
    float theta1[4];
    float theta2[4];
    float eta[4];
    float scale[3];

    float h;

    Prarx(){
        h = 0.1;

        ////Constant model
		theta1[0] =   0.0;
		theta1[1] =   0.0;
		theta1[2] =   0.0;
		theta1[3] =   0.0;
		theta2[0] =   0.0;
		theta2[1] =   0.0;
		theta2[2] =   0.0;
		theta2[3] =   0.0;
		eta   [0] =  10.5552;
		eta   [1] =   1.6370;
		eta   [2] =   4.8552;
		eta   [3] =  -4.8363;
		scale [0] = 108.2375;
		scale [1] =   2.7996;
		scale [2] =   0.4627;
    }

    void cal_output(const x_t &in_x, const int i, double* out_y){
        //Convert the state vector into the inputs for the model: distance, relative velocity, acceleration
		double xc[3];
        double theta1_phi, theta2_phi, eta_phi, w, P;

        xc[0] = in_x[3*i+0];  //distance
		xc[1] = in_x[3*(i-1)+1] - in_x[3*i+1];  //relative velocity (cannot be used in case of the first car)
		//xc[1] = (i==0 ? 0 : in_x[3*(i-1)+1]) - in_x[3*i+1];  //relative velocity
		xc[2] = in_x[3*i+2];

		xc[0] /= scale[0];
		xc[1] /= scale[1];
		xc[2] /= scale[2];

		theta1_phi = theta1[0]*xc[0] + theta1[1]*xc[1] + theta1[2]*xc[2] + theta1[3];
		theta2_phi = theta2[0]*xc[0] + theta2[1]*xc[1] + theta2[2]*xc[2] + theta2[3];
		eta_phi    = eta[0]*xc[0] + eta[1]*xc[1] + eta[2]*xc[2] + eta[3];
		
		/*double xn[DimX];
		xn[0] = (x[0] - norm_mean[0]) / norm_std[0];
		xn[1] = (x[1] - norm_mean[1]) / norm_std[1];
		xn[2] = (x[2] - norm_mean[2]) / norm_std[2];
		*theta1_phi = theta1[0]*xn[0] + theta1[1]*xn[1] + theta1[2]*xn[2] + theta1[3];
		*theta2_phi = theta2[0]*xn[0] + theta2[1]*xn[1] + theta2[2]*xn[2] + theta2[3];
		*eta_phi    = eta[0]*xn[0] + eta[1]*xn[1] + eta[2]*xn[2] + eta[3];*/
		
		double theta_phi_lim = 5.0/scale[2];
		if(theta1_phi > theta_phi_lim)
			theta1_phi = theta_phi_lim;
		else if(theta1_phi < -theta_phi_lim)
			theta1_phi = -theta_phi_lim;

		if(theta2_phi > theta_phi_lim)
			theta2_phi = theta_phi_lim;
		else if(theta2_phi < -theta_phi_lim)
			theta2_phi = -theta_phi_lim;

		double lim = 20.0;
		if(eta_phi > lim)
			eta_phi = lim;
		if(eta_phi < -lim)
			eta_phi = -lim;

		//< Set boundary on the theta_phi with reasonable value for acceleration @2018.07.13
		lim = 5.0 / scale[2];
		if (theta1_phi > lim)
			theta1_phi = lim;
		else if (theta1_phi < -lim)
			theta1_phi = -lim;
		if (theta2_phi > lim)
			theta2_phi = lim;
		else if (theta2_phi < -lim)
			theta2_phi = -lim;

		w = exp(eta_phi);
		
		P = 1 / (w + 1);

        *out_y = scale[2] * ((1 - P) * theta1_phi + P * theta2_phi);
    }

    void cal_output(const x_t &in_x, const int i, double* out_y, double* theta1_phi, double* theta2_phi, double* eta_phi, double* w, double* P)
	{
		double xc[3];

        xc[0] = in_x[3*i+0];  //distance
		xc[1] = (i==0 ? 0 : in_x[3*(i-1)+1]) - in_x[3*i+1];  //relative velocity
		xc[2] = in_x[3*i+2];

		xc[0] /= scale[0];
		xc[1] /= scale[1];
		xc[2] /= scale[2];

		*theta1_phi = theta1[0]*xc[0] + theta1[1]*xc[1] + theta1[2]*xc[2] + theta1[3];
		*theta2_phi = theta2[0]*xc[0] + theta2[1]*xc[1] + theta2[2]*xc[2] + theta2[3];
		*eta_phi    = eta[0]*xc[0] + eta[1]*xc[1] + eta[2]*xc[2] + eta[3];
		
		/*double xn[DimX];
		xn[0] = (x[0] - norm_mean[0]) / norm_std[0];
		xn[1] = (x[1] - norm_mean[1]) / norm_std[1];
		xn[2] = (x[2] - norm_mean[2]) / norm_std[2];
		*theta1_phi = theta1[0]*xn[0] + theta1[1]*xn[1] + theta1[2]*xn[2] + theta1[3];
		*theta2_phi = theta2[0]*xn[0] + theta2[1]*xn[1] + theta2[2]*xn[2] + theta2[3];
		*eta_phi    = eta[0]*xn[0] + eta[1]*xn[1] + eta[2]*xn[2] + eta[3];*/
		
		double theta_phi_lim = 5.0/scale[2];
		if(*theta1_phi > theta_phi_lim)
			*theta1_phi = theta_phi_lim;
		else if(*theta1_phi < -theta_phi_lim)
			*theta1_phi = -theta_phi_lim;

		if(*theta2_phi > theta_phi_lim)
			*theta2_phi = theta_phi_lim;
		else if(*theta2_phi < -theta_phi_lim)
			*theta2_phi = -theta_phi_lim;

		double lim = 20.0;
		if(*eta_phi > lim)
			*eta_phi = lim;
		if(*eta_phi < -lim)
			*eta_phi = -lim;

		//< Set boundary on the theta_phi with reasonable value for acceleration @2018.07.13
		lim = 5.0 / scale[2];
		if (*theta1_phi > lim)
			*theta1_phi = lim;
		else if (*theta1_phi < -lim)
			*theta1_phi = -lim;
		if (*theta2_phi > lim)
			*theta2_phi = lim;
		else if (*theta2_phi < -lim)
			*theta2_phi = -lim;

		*w = exp(*eta_phi);
		
		*P = 1 / (*w + 1);
        
        *out_y = scale[2] * ((1 - *P) * *theta1_phi + *P * *theta2_phi);
	}

    void cal_dt(const x_t &in_x, const int i, double* out_dt){
        double y;
        this->cal_output(in_x, i, &y);
        *out_dt = (y - in_x[3*i+2])/h;
    }

    void cal_dfdx(const x_t &in_x, const int i, x_t* out_dfdx){
        double y, theta1_phi, theta2_phi, eta_phi, w, P;
		double tmp;
        double M[3];
        double P_phi[3];

        for(int ic = 0; ic < 3*NCAR; ic++){
            *out_dfdx[ic] = 0.0;
        }

        cal_output(in_x, i, &y, &theta1_phi, &theta2_phi, &eta_phi, &w, &P);
        tmp = w / ((1+w)*(1+w));
				
        P_phi[0] = eta[0] * tmp;
		P_phi[1] = eta[1] * tmp;
		P_phi[2] = eta[2] * tmp;

        M[0] = scale[2] * (P_phi[0] * (theta2_phi - theta1_phi) + (1 - P)*theta1[0] + P*theta2[0]) / scale[0];
		M[1] = scale[2] * (P_phi[1] * (theta2_phi - theta1_phi) + (1 - P)*theta1[1] + P*theta2[1]) / scale[1];
		M[2] = scale[2] * (P_phi[2] * (theta2_phi - theta1_phi) + (1 - P)*theta1[2] + P*theta2[2]) / scale[2];

        *out_dfdx[3*i+0] = M[0]/h * 1;
        *out_dfdx[3*i+1] = M[1]/h * (-1);
		if(i != 0) *out_dfdx[3*(i-1)+1] += M[1]/h * 1;
        *out_dfdx[3*i+2] = (M[2]-1)/h * 1;	
    }
};
/*
class Prarx_1 : public Prarx<1>{
public:
	Prarx_1():Prarx<1>(){}
};
class Prarx_2 : public Prarx<2>{
public:
	Prarx_2():Prarx<2>(){}
};
class Prarx_3 : public Prarx<3>{
public:
	Prarx_3():Prarx<3>(){}
};
class Prarx_4 : public Prarx<4>{
public:
	Prarx_4():Prarx<4>(){}
};
class Prarx_5 : public Prarx<5>{
public:
	Prarx_5():Prarx<5>(){}
};
class Prarx_6 : public Prarx<6>{
public:
	Prarx_6():Prarx<6>(){}
};
class Prarx_7 : public Prarx<7>{
public:
	Prarx_7():Prarx<7>(){}
};
class Prarx_8 : public Prarx<8>{
public:
	Prarx_8():Prarx<8>(){}
};
class Prarx_9 : public Prarx<9>{
public:
	Prarx_9():Prarx<9>(){}
};*/


#endif