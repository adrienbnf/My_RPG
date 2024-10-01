// fragment_shader.frag
uniform sampler2D texture;
uniform vec3 gray_shaves;
uniform bool isGray;
uniform bool restoreSomeColor;
uniform bool restoreMoreColor;
uniform bool restoreFullColor;

void main()
{
    vec4 color = texture2D(texture, gl_TexCoord[0].xy);

    if (isGray)
    {
        float gray = dot(color.rgb, vec3(0.2126, 0.7152, 0.0722));
        color.rgb = vec3(gray);
    }
    else
    {
        if (restoreFullColor)
        {}
        else if (restoreMoreColor)
        {
            color.rgb += 0.2;
        }
        else if (restoreSomeColor)
        {
            color.rgb += 0.3;
        }
        else
        {
            float gray = dot(color.rgb, vec3(0.2126, 0.7152, 0.0722));
            color.rgb = vec3(gray);
        }
    }

    gl_FragColor = color;
}
