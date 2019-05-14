class adc2_matrix : public adc2_matrix_h {
private:
    any_tensor<2, double> &f_vv; // F_{ab}, F is Fock matrix
    any_tensor<2, double> &f_oo; // F_{ij}, F is Fock matrix
    any_tensor<4, double> &i_ovvv; // <ai||jk>
public:
    adc2_matrix(
        any_tensor<2, double> &f_vv_,
        any_tensor<2, double> &f_oo_,
        any_tensor<4, double> &i_ovvv_,
        any_tensor<2, double> &i1_) : // I in Eq. 3.7
        adc2_matrix_h(i1_), f_vv(f_vv_), f_oo(f_oo_), i_ovvv(i_ovvv_) { }
    virtual ~adc2_matrix() { }

    virtual void multiply(expr_lhs<1, double> &r1, expr_lhs<3, double> &r2,
            any_tensor<1, double> &u1, any_tensor<3, double> &u2) {

        adc2_matrix::start_timer();
        adc2_u1(i_ovvv, i1, u1, u2).compute(r1); 
		// r1 is the result of matrix vector product W_{a}
        adc2_u2(f_vv, f_oo, i_ovvv, u1, u2).compute(r2);
		// r2 is the result of matrix vector product W_{abi}
        adc2_matrix::stop_timer();
    }
};
