// Author @patriciogv - 2015
// http://patriciogonzalezvivo.com

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

void main(){
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    vec3 color = vec3(0.0);

    // bottom-left
    vec2 bl = step(vec2(0.03),vec2(1.-mod((st.x+0.8),1.),1.-mod((st.y+0.4),1.)));
    float pct = bl.x * bl.y;
    vec2 b2 = step(vec2(0.03),vec2(1.-mod((st.x+0.22),1.),1.-mod((st.y+0.2),1.)));
    pct *= b2.x * b2.y;
    vec2 b3 = step(vec2(0.03),vec2(1.-mod((st.x+0.05),1.),1.-mod((st.y+0.9),1.)));
    pct *= b3.x * b3.y;
    vec2 block_red =vec2(step(0.2,st.x),step(0.4,1.-st.y));
    vec3 color_red = vec3(1.0,block_red.x>block_red.y?block_red.x:block_red.y,block_red.x>block_red.y?block_red.x:block_red.y);
    color = vec3(pct*color_red);
    vec2 block_blue =vec2(step(0.22,1.-st.x),step(0.1,st.y));
    vec3 color_blue = vec3(block_blue.x>block_blue.y?block_blue.x:block_blue.y,block_blue.x>block_blue.y?block_blue.x:block_blue.y,0.9);
    color = vec3(color*color_blue);
    
    vec2 block_yellow =vec2(step(0.05,1.-st.x),step(0.4,1.-st.y));
    vec3 color_yellow = vec3(1.0,1.0,block_yellow.x>block_yellow.y?block_yellow.x:block_yellow.y);
    color = vec3(color*color_yellow);
    

    gl_FragColor = vec4(color,1.0);
}

