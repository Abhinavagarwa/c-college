
# parsetab.py
# This file is automatically generated. Do not edit.
# pylint: disable=W,C,R
_tabversion = '3.10'

_lr_method = 'LALR'

_lr_signature = 'leftPLUSMINUSleftTIMESDIVIDErightPOWERrightUMINUSDIVIDE LPAREN MINUS NUMBER PLUS POWER RPAREN TIMESexpression : expression PLUS expression\n                  | expression MINUS expression\n                  | expression TIMES expression\n                  | expression DIVIDE expression\n                  | expression POWER expressionexpression : MINUS expression %prec UMINUSexpression : LPAREN expression RPARENexpression : NUMBER'
    
_lr_action_items = {'MINUS':([0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,],[2,6,2,2,-8,2,2,2,2,2,-6,6,-1,-2,-3,-4,-5,-7,]),'LPAREN':([0,2,3,5,6,7,8,9,],[3,3,3,3,3,3,3,3,]),'NUMBER':([0,2,3,5,6,7,8,9,],[4,4,4,4,4,4,4,4,]),'$end':([1,4,10,12,13,14,15,16,17,],[0,-8,-6,-1,-2,-3,-4,-5,-7,]),'PLUS':([1,4,10,11,12,13,14,15,16,17,],[5,-8,-6,5,-1,-2,-3,-4,-5,-7,]),'TIMES':([1,4,10,11,12,13,14,15,16,17,],[7,-8,-6,7,7,7,-3,-4,-5,-7,]),'DIVIDE':([1,4,10,11,12,13,14,15,16,17,],[8,-8,-6,8,8,8,-3,-4,-5,-7,]),'POWER':([1,4,10,11,12,13,14,15,16,17,],[9,-8,-6,9,9,9,9,9,9,-7,]),'RPAREN':([4,10,11,12,13,14,15,16,17,],[-8,-6,17,-1,-2,-3,-4,-5,-7,]),}

_lr_action = {}
for _k, _v in _lr_action_items.items():
   for _x,_y in zip(_v[0],_v[1]):
      if not _x in _lr_action:  _lr_action[_x] = {}
      _lr_action[_x][_k] = _y
del _lr_action_items

_lr_goto_items = {'expression':([0,2,3,5,6,7,8,9,],[1,10,11,12,13,14,15,16,]),}

_lr_goto = {}
for _k, _v in _lr_goto_items.items():
   for _x, _y in zip(_v[0], _v[1]):
       if not _x in _lr_goto: _lr_goto[_x] = {}
       _lr_goto[_x][_k] = _y
del _lr_goto_items
_lr_productions = [
  ("S' -> expression","S'",1,None,None,None),
  ('expression -> expression PLUS expression','expression',3,'p_expression_binop','2.py',58),
  ('expression -> expression MINUS expression','expression',3,'p_expression_binop','2.py',59),
  ('expression -> expression TIMES expression','expression',3,'p_expression_binop','2.py',60),
  ('expression -> expression DIVIDE expression','expression',3,'p_expression_binop','2.py',61),
  ('expression -> expression POWER expression','expression',3,'p_expression_binop','2.py',62),
  ('expression -> MINUS expression','expression',2,'p_expression_uminus','2.py',66),
  ('expression -> LPAREN expression RPAREN','expression',3,'p_expression_group','2.py',70),
  ('expression -> NUMBER','expression',1,'p_expression_number','2.py',74),
]
