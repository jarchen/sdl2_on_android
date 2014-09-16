package my.app;

import org.libsdl.app.SDLActivity;

import android.os.Bundle;
import android.util.Log;

public class MainActivity extends SDLActivity {
	private final String TAG = "MainActivity";
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		Log.i(TAG, "Start MainActivity");
	}
}
