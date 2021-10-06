#include "pch.h"
#include "CppUnitTest.h"
#include "../SmokingGunInteractiveTest/Rectangle2D.h"
#include "../SmokingGunInteractiveTest/Rectangle2D.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
	TEST_CLASS(Rectangle2DTest)
	{
		public:	
			TEST_METHOD(HandlesEqualRects)
			{
				Rectangle2D rectA = Rectangle2D();
				Rectangle2D rectB = Rectangle2D();
				Assert::IsTrue(rectA == rectB);
			}

			TEST_METHOD(EqualRectsIntersect)
			{
				Rectangle2D rectA = Rectangle2D();
				Rectangle2D rectB = Rectangle2D();
				Assert::IsTrue(rectA.IntersectsWith(rectB));
			}

			TEST_METHOD(CollisionDetectionIsInterchangeable)
			{
				Rectangle2D rectA = Rectangle2D();
				Rectangle2D rectB = Rectangle2D(Vector2D(0, 0.5), 1, 1);
				Assert::IsTrue(rectA.IntersectsWith(rectB));
				Assert::IsTrue(rectB.IntersectsWith(rectA));
			}

			TEST_METHOD(HandlesRectsToTheSide)
			{
				Rectangle2D rectA = Rectangle2D();
				Rectangle2D rectB = Rectangle2D(Vector2D(1, 0), 1, 1);
				Rectangle2D rectC = Rectangle2D(Vector2D(2, 0), 1, 1);
				Assert::IsFalse(rectA.IntersectsWith(rectB));
				Assert::IsFalse(rectA.IntersectsWith(rectC));
				Assert::IsFalse(rectB.IntersectsWith(rectC));
			}

			TEST_METHOD(HandlesRectsAboveAndBelow)
			{
				Rectangle2D rectA = Rectangle2D();
				Rectangle2D rectB = Rectangle2D(Vector2D(0, 1), 1, 1);
				Rectangle2D rectC = Rectangle2D(Vector2D(0, 2), 1, 1);
				Assert::IsFalse(rectA.IntersectsWith(rectB));
				Assert::IsFalse(rectA.IntersectsWith(rectC));
				Assert::IsFalse(rectB.IntersectsWith(rectC));
			}
	};
}
