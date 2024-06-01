#pragma once


class Particule;
class Systeme;
class Enceinte;
class Neon;
class Argon;
class ParticuleTrajet;

class SupportADessin
{
 public:

  SupportADessin() = default;

  virtual void dessine(Particule   const& a_dessiner)       = 0;
  virtual void dessine(Enceinte   const& a_dessiner)        = 0;
  virtual void dessine(Systeme   const& a_dessiner)         = 0;
  virtual void dessine(ParticuleTrajet   const& a_dessiner) = 0;
  virtual void dessine(Neon   const& a_dessiner)            = 0;
  virtual void dessine(Argon   const& a_dessiner)           = 0;

  SupportADessin(SupportADessin const&)            = delete;
  SupportADessin& operator=(SupportADessin const&) = delete;
  SupportADessin(SupportADessin&&)            = default;
  SupportADessin& operator=(SupportADessin&&) = default;

  virtual ~SupportADessin() = default;

};

