#ifndef HEADER_SYNTAX_TREE_HPP
#define HEADER_SYNTAX_TREE_HPP

#include <boost/scoped_ptr.hpp>
#include <vector>

#include "value.hpp"
#include "environment.hpp"

class Expr
{
public:
  virtual ~Expr() {}
  virtual Value eval(const Environment& env) const =0;
};

class Plus : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  Plus(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) + m_rhs->eval(env);
  }

private:
  Plus(const Plus&);
  Plus& operator=(const Plus&);
};

class Minus : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  Minus(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) - m_rhs->eval(env);
  }

private:
  Minus(const Minus&);
  Minus& operator=(const Minus&);
};

class Mult : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  Mult(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) * m_rhs->eval(env);
  }

private:
  Mult(const Mult&);
  Mult& operator=(const Mult&);
};

class Div : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  Div(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) / m_rhs->eval(env);
  }

private:
  Div(const Div&);
  Div& operator=(const Div&);
};

class Modulo : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  Modulo(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) % m_rhs->eval(env);
  }

private:
  Modulo(const Modulo&);
  Modulo& operator=(const Modulo&);
};

class BitwiseAND : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  BitwiseAND(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) & m_rhs->eval(env);
  }

private:
  BitwiseAND(const BitwiseAND&);
  BitwiseAND& operator=(const BitwiseAND&);
};

class BitwiseXOR : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  BitwiseXOR(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) ^ m_rhs->eval(env);
  }

private:
  BitwiseXOR(const BitwiseXOR&);
  BitwiseXOR& operator=(const BitwiseXOR&);
};

class BitwiseOR : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  BitwiseOR(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) | m_rhs->eval(env);
  }

private:
  BitwiseOR(const BitwiseOR&);
  BitwiseOR& operator=(const BitwiseOR&);
};

class Equal : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  Equal(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) == m_rhs->eval(env);
  }

private:
  Equal(const Equal&);
  Equal& operator=(const Equal&);
};

class NotEqual : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  NotEqual(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) != m_rhs->eval(env);
  }

private:
  NotEqual(const NotEqual&);
  NotEqual& operator=(const NotEqual&);
};

class LargerThen : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  LargerThen(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) > m_rhs->eval(env);
  }

private:
  LargerThen(const LargerThen&);
  LargerThen& operator=(const LargerThen&);
};

class SmallerThen : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  SmallerThen(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) < m_rhs->eval(env);
  }

private:
  SmallerThen(const SmallerThen&);
  SmallerThen& operator=(const SmallerThen&);
};

class SmallerOrEqualThen : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  SmallerOrEqualThen(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) <= m_rhs->eval(env);
  }

private:
  SmallerOrEqualThen(const SmallerOrEqualThen&);
  SmallerOrEqualThen& operator=(const SmallerOrEqualThen&);
};

class LargerOrEqualThen : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  LargerOrEqualThen(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) >= m_rhs->eval(env);
  }

private:
  LargerOrEqualThen(const LargerOrEqualThen&);
  LargerOrEqualThen& operator=(const LargerOrEqualThen&);
};


class ShiftLeft : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  ShiftLeft(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) << m_rhs->eval(env);
  }

private:
  ShiftLeft(const ShiftLeft&);
  ShiftLeft& operator=(const ShiftLeft&);
};

class ShiftRight : public Expr
{
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  ShiftRight(Expr* lhs, Expr* rhs) :
    m_lhs(lhs), 
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return m_lhs->eval(env) >> m_rhs->eval(env);
  }

private:
  ShiftRight(const ShiftRight&);
  ShiftRight& operator=(const ShiftRight&);
};

class LogicalNOT : public Expr
{
private:
  boost::scoped_ptr<Expr> m_rhs;

public:
  LogicalNOT(Expr* rhs) :
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return !m_rhs->eval(env);
  }
};

class BitwiseNOT : public Expr
{
private:
  boost::scoped_ptr<Expr> m_rhs;

public:
  BitwiseNOT(Expr* rhs) :
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    return ~m_rhs->eval(env);
  }
};


class Condition : public Expr
{
  boost::scoped_ptr<Expr> m_expr;
  boost::scoped_ptr<Expr> m_lhs;
  boost::scoped_ptr<Expr> m_rhs;

public:
  Condition(Expr* expr, Expr* lhs, Expr* rhs) :
    m_expr(expr),
    m_lhs(lhs),
    m_rhs(rhs)
  {}

  Value eval(const Environment& env) const
  {
    if (m_expr->eval(env))
    {
      return m_lhs->eval(env);
    }
    else
    {
      return m_rhs->eval(env);
    }
  }   
};

class Negate : public Expr
{
private:
  boost::scoped_ptr<Expr> m_expr;

public:
  Negate(Expr* expr) :
    m_expr(expr)
  {}

  Value eval(const Environment& env) const
  {
    return -m_expr->eval(env);
  }
};

class Function : public Expr
{
private:
  std::string m_name;
  std::vector<Expr*> m_args; // FIXME: memleak

public:
  Function(const std::string& name, const std::vector<Expr*>& args) :
    m_name(name),
    m_args(args)
  {}

  Value eval(const Environment& env) const
  {
    std::vector<Value> values;
    for(std::vector<Expr*>::const_iterator i = m_args.begin(); i != m_args.end(); ++i)
    {
      values.push_back((*i)->eval(env));
    }
    return env.lookup_function(m_name)(values);
  }
};

class Variable : public Expr
{
private:
  std::string m_name;

public:
  Variable(const std::string& name) :
    m_name(name)
  {}

  Value eval(const Environment& env) const
  {
    return env.lookup_variable(m_name);
  }
};

class Integer : public Expr
{
  int m_value;

public:
  Integer(int value) :
    m_value(value)
  {}

  Value eval(const Environment& env) const
  {
    return Value::integer(m_value);
  }

private:
  Integer(const Integer&);
  Integer& operator=(const Integer&);
};

class Real : public Expr
{
  float m_value;

public:
  Real(float value) :
    m_value(value)
  {}

  Value eval(const Environment& env) const
  {
    return Value::real(m_value);
  }

private:
  Real(const Real&);
  Real& operator=(const Real&);
};

#endif

/* EOF */
