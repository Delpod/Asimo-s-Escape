#ifndef RAYCASTANYCALLBACK_H
#define RAYCASTANYCALLBACK_H
#include <Box2D/Box2D.h>

class RayCastAnyCallback : public b2RayCastCallback {
public:
   RayCastAnyCallback() {
      m_hit = false;
   }
   
   float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point,
                    const b2Vec2& normal, float32 fraction) {
      b2Body* body = fixture->GetBody();
      void* userData = body->GetUserData();
      if (userData) {
         int32 index = *(int32*)userData;
         if (index == 0) {
            return -1.0f;
         }
      }
      
      m_hit = true;
      m_point = point;
      m_normal = normal;
      m_body = body;

      return 0.0f;
   }
   
   bool m_hit;
   b2Vec2 m_point;
   b2Vec2 m_normal;
   b2Body* m_body;
};

#endif // RAYCASTANYCALLBACK_H