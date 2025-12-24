package com.example.xplay

import android.Manifest
import android.content.pm.PackageManager
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.Surface
import android.view.SurfaceHolder
import android.widget.TextView
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import androidx.lifecycle.lifecycleScope
import androidx.lifecycle.viewmodel.InitializerViewModelFactoryBuilder
import com.example.xplay.databinding.ActivityMainBinding
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

class MainActivity : AppCompatActivity(), SurfaceHolder.Callback {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // 动态申请存储权限
        requestPermissions()

        // Example of a call to a native method
        binding.sampleText.text = stringFromJNI()
    }

    /**
     * A native method that is implemented by the 'xplay' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String
    external fun InitView(surface: Surface)

    companion object {
        // Used to load the 'xplay' library on application startup.
        init {
            System.loadLibrary("xplay")
        }
    }

    // 申请权限
    private fun requestPermissions() {
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.READ_EXTERNAL_STORAGE)
            != PackageManager.PERMISSION_GRANTED
        ) {
            ActivityCompat.requestPermissions(
                this,
                arrayOf(Manifest.permission.READ_EXTERNAL_STORAGE),
                1001
            )
        }
    }

    override fun surfaceCreated(holder: SurfaceHolder) {
        // 初始化opengl egl显示
        InitView(holder.surface);
    }


    override fun surfaceChanged(holder: SurfaceHolder, format: Int, width: Int, height: Int) {
        // Surface 尺寸或格式改变时的处理
    }

    override fun surfaceDestroyed(holder: SurfaceHolder) {
        // Surface 销毁时的处理
    }

    override fun onDestroy() {
        super.onDestroy()
//        stopPlay()
    }

}