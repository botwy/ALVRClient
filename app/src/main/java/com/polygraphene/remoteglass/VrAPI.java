package com.polygraphene.remoteglass;

import android.app.Activity;
import android.view.Surface;

public class VrAPI {
    native void init();
    native void onSurfaceCreated(Surface surface, Activity activity);
    native void render();
    native void onSurfaceDestroyed();
}