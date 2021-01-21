friend string to_string(const Pizza &p)
{
    string res = "";
    #ifdef Dhiraj
    {
        res += "[";
        res += to_string(p.id);
        res += ", " + to_string(p.ingre);
        res += "]";
    }
    #endif
    return res;
}

friend string to_string(const Input &in)
{
    string res = "";
    #ifdef Dhiraj
    {
        res += "[";
        res += to_string(in.M) + ", ";
        res += to_string(in.T2) + ", ";
        res += to_string(in.T3) + ", ";
        res += to_string(in.T4) + "]\n";
        res += to_string(in.p);
    }
    #endif
    return res;
}