#TODO: revisit in C++
class Solution(object):
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        stack = []

        for asteroid in asteroids:
            
            while stack and asteroid < 0 and stack[-1] > 0:
                leadingAsteroid = asteroid
                leftAsteroid = stack[-1]

                if abs(leftAsteroid) - abs(leadingAsteroid) < 0 and leadingAsteroid < 0:
                    winningAsteroid = leadingAsteroid
                    stack.pop()
                    continue
                if abs(leftAsteroid) - abs(leadingAsteroid) == 0:
                    # both asteroids annihilated 
                    stack.pop()
                break

            else:
                stack.append(asteroid)

        return stack